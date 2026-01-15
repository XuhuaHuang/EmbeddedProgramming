/**
 * @file legacy_tree.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2025-12-23
 *
 * https://en.cppreference.com/w/cpp/concepts/default_initializable.html
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef TREE_HPP
#define TREE_HPP

#include <concepts>
#include <expected>
#include <string>

namespace ds {

/**
 * @brief Error codes for tree operations
 *
 */
struct tree_error {
  tree_error(const tree_error&)            = default;
  tree_error(tree_error&&)                 = default;
  tree_error& operator=(const tree_error&) = default;
  tree_error& operator=(tree_error&&)      = default;

  enum class code { invalid_node, invalid_parent, cannot_remove_root, would_create_cycle, out_of_range };

  code        c{};
  std::string message{};

  friend auto to_string(const tree_error& e) -> std::string { return e.message; }
};

template <typename T>
  requires std::default_initializable<T> and std::is_arithmetic_v<T>
class tree final {
public:
  using value_type = T;
  using size_type  = std::size_t;

  struct node_id final {
    explicit node_id() = default;
    explicit node_id(std::uint32_t idx, std::uint32_t gen) noexcept
      : index{idx}
      , generation{gen} {}
    explicit node_id(std::uint32_t index) noexcept
      : index{index}
      , generation{0} {}

    std::uint32_t index{};
    std::uint32_t generation{};

    explicit constexpr operator bool() const noexcept { return index != 0; }

    explicit constexpr operator std::size_t() const noexcept { return static_cast<std::size_t>(index); }

    friend constexpr auto operator==(node_id a, node_id b) -> bool = default;
    friend constexpr auto operator!=(node_id a, node_id b) -> bool = default;
    friend constexpr auto operator<=>(node_id a, node_id b)        = default;
  };

  struct node_handle final {
    static constexpr inline std::uint32_t invalid_id = 0;

    node_id id{invalid_id};

    friend constexpr bool operator==(node_handle a, node_handle b) noexcept { return a.id == b.id; }
    friend constexpr bool operator!=(node_handle a, node_handle b) noexcept { return !(a == b); }
    friend constexpr bool operator<(node_handle a, node_handle b) noexcept { return a.id < b.id; }

    explicit constexpr operator bool() const noexcept { return id != invalid_id; }
  };

private:
  struct node final {
    T                      value{};
    std::optional<node_id> parent{};
    std::vector<node_id>   children{};
    std::uint32_t          generation{node_handle::invalid_id};
    bool                   alive{true};
  };

  // index 0 unused so that invalid_id=0 is never a valid node
  std::vector<node>          nodes_{};
  node_handle                root_{};
  std::vector<std::uint32_t> free_list_{};

  /**
   * @brief Construct a new tree object
   * @note Default constructor
   */
  tree() = default;

  // Construct a tree with a root value
  explicit tree(const T& root_value) { (void)emplace_root(root_value); }
  explicit tree(T&& root_value) { (void)emplace_root(std::move(root_value)); }

  [[nodiscard]]
  auto empty() const -> bool {
    return !root_.id == node_handle::invalid_id;
  }
  [[nodiscard]]
  auto root() const -> node_handle {
    return this->root_;
  }

  [[nodiscard]]
  auto is_valid(node_id id) const -> bool {
    if (id.index >= nodes_.size())
      return false;
    const auto& n = nodes_[id.index];
    return n.alive && n.generation == id.generation;
  }

  [[nodiscard]]
  auto value(node_id id) -> std::expected<T&, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    return nodes_[id.index].value;
  }

  [[nodiscard]]
  auto value(node_id id) const -> std::expected<const T&, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    return nodes_[id.index].value;
  }

  [[nodiscard]]
  auto parent(node_id id) const -> std::expected<std::optional<node_id>, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    return nodes_[id.index].parent;
  }

  [[nodiscard]]
  auto children(node_id id) const -> std::expected<const std::vector<node_id>&, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    return nodes_[id.index].children;
  }

  // Creation

  auto emplace_root(T v) -> std::expected<node_id, tree_error> {
    if (root_.has_value()) {
      return std::unexpected(err(tree_error::code::out_of_range, "Root already exists."));
    }

    node_id id{static_cast<std::uint32_t>(nodes_.size()), 0};
    nodes_.push_back(node{.value = std::move(v), .parent = std::nullopt, .children = {}, .generation = 0, .alive = true}
    );
    root_ = id;
    return id;
  }

  auto add_child(node_id parent_id, T v) -> std::expected<node_id, tree_error> {
    if (!is_valid(parent_id)) {
      return std::unexpected(err(tree_error::code::invalid_parent, "Parent node_id is invalid."));
    }

    node_id child_id{static_cast<std::uint32_t>(nodes_.size()), 0};
    nodes_.push_back(node{.value = std::move(v), .parent = parent_id, .children = {}, .generation = 0, .alive = true});
    nodes_[parent_id.index].children.push_back(child_id);
    return child_id;
  }

  // Structural operations
  // Remove an entire subtree rooted at id.
  // Root cannot be removed (use clear()).
  auto remove_subtree(node_id id) -> std::expected<void, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    if (root_.has_value() && *root_ == id) {
      return std::unexpected(err(tree_error::code::cannot_remove_root, "Cannot remove root. Use clear()."));
    }

    // Detach from parent first.
    if (auto p = nodes_[id.index].parent; p.has_value()) {
      auto& siblings = nodes_[p->index].children;
      erase_one(siblings, id);
      nodes_[id.index].parent.reset();
    }

    // Mark nodes in subtree as dead (generation increments to invalidate
    // handles).
    std::deque<node_id> q;
    q.push_back(id);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      if (!is_valid(cur))
        continue; // could be revisited; harmless

      auto& n = nodes_[cur.index];
      for (auto c : n.children)
        q.push_back(c);

      n.children.clear();
      n.parent.reset();
      n.alive = false;
      ++n.generation;
    }

    return {};
  }

  // Move subtree rooted at 'subtree_root' under 'new_parent'.
  auto move_subtree(node_id subtree_root, node_id new_parent) -> std::expected<void, tree_error> {
    if (!is_valid(subtree_root))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid subtree_root."));
    if (!is_valid(new_parent))
      return std::unexpected(err(tree_error::code::invalid_parent, "Invalid new_parent."));
    if (root_.has_value() && *root_ == subtree_root) {
      return std::unexpected(err(tree_error::code::out_of_range, "Moving the root is not supported in this ADT."));
    }
    if (subtree_root == new_parent) {
      return std::unexpected(err(tree_error::code::would_create_cycle, "Cannot parent a node to itself."));
    }
    // Prevent cycles: new_parent must not be inside subtree_root's subtree.
    if (is_descendant(new_parent, subtree_root)) {
      return std::unexpected(err(tree_error::code::would_create_cycle, "Move would create a cycle."));
    }

    // Detach from old parent
    if (auto old_p = nodes_[subtree_root.index].parent; old_p.has_value()) {
      auto& siblings = nodes_[old_p->index].children;
      erase_one(siblings, subtree_root);
    }

    // Attach to new parent
    nodes_[subtree_root.index].parent = new_parent;
    nodes_[new_parent.index].children.push_back(subtree_root);

    return {};
  }

  // Queries
  // Depth: number of edges from root to this node.
  auto depth(node_id id) const -> std::expected<std::size_t, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    std::size_t d   = 0;
    auto        cur = nodes_[id.index].parent;
    while (cur.has_value()) {
      if (!is_valid(*cur))
        break;
      ++d;
      cur = nodes_[cur->index].parent;
    }
    return d;
  }

  // Subtree size (including this node).
  auto subtree_size(node_id id) const -> std::expected<std::size_t, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    std::size_t         count = 0;
    std::deque<node_id> q;
    q.push_back(id);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      if (!is_valid(cur))
        continue;
      ++count;
      for (auto c : nodes_[cur.index].children)
        q.push_back(c);
    }
    return count;
  }

  // Height: max number of edges from id down to a leaf.
  auto height(node_id id) const -> std::expected<std::size_t, tree_error> {
    if (!is_valid(id))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid node_id."));
    return height_impl(id);
  }

  // Traversals
  template <class Fn>
    requires std::invocable<Fn, node_id, const value_type&>
  auto preorder(node_id start, Fn&& fn) const -> std::expected<void, tree_error> {
    if (!is_valid(start))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid start node."));
    std::vector<node_id> stack;
    stack.push_back(start);

    while (!stack.empty()) {
      auto cur = stack.back();
      stack.pop_back();
      if (!is_valid(cur))
        continue;

      fn(cur, nodes_[cur.index].value);

      // push children in reverse so first child is visited first
      const auto& ch = nodes_[cur.index].children;
      for (std::size_t i = ch.size(); i-- > 0;)
        stack.push_back(ch[i]);
    }
    return {};
  }

  template <class Fn>
    requires std::invocable<Fn, node_id, const value_type&>
  auto postorder(node_id start, Fn&& fn) const -> std::expected<void, tree_error> {
    if (!is_valid(start))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid start node."));
    // Two-stack postorder
    std::vector<node_id> s1, s2;
    s1.push_back(start);

    while (!s1.empty()) {
      auto cur = s1.back();
      s1.pop_back();
      if (!is_valid(cur))
        continue;

      s2.push_back(cur);
      for (auto c : nodes_[cur.index].children)
        s1.push_back(c);
    }

    while (!s2.empty()) {
      auto cur = s2.back();
      s2.pop_back();
      if (!is_valid(cur))
        continue;
      fn(cur, nodes_[cur.index].value);
    }
    return {};
  }

  template <class Fn>
    requires std::invocable<Fn, node_id, const value_type&>
  auto level_order(node_id start, Fn&& fn) const -> std::expected<void, tree_error> {
    if (!is_valid(start))
      return std::unexpected(err(tree_error::code::invalid_node, "Invalid start node."));
    std::deque<node_id> q;
    q.push_back(start);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop_front();
      if (!is_valid(cur))
        continue;

      fn(cur, nodes_[cur.index].value);

      for (auto c : nodes_[cur.index].children)
        q.push_back(c);
    }
    return {};
  }

  // Utilities

  void clear() {
    nodes_.clear();
    root_.reset();
  }

private:
  static auto err(tree_error::code c, std::string msg) -> tree_error {
    return tree_error{.c = c, .message = std::move(msg)};
  }

  static void erase_one(std::vector<node_id>& v, node_id x) {
    for (auto it = v.begin(); it != v.end(); ++it) {
      if (*it == x) {
        v.erase(it);
        return;
      }
    }
  }

  auto is_descendant(node_id candidate, node_id ancestor) const -> bool {
    // Walk up from candidate to root; if we meet ancestor, candidate is in
    // ancestor's subtree.
    auto cur = std::optional<node_id>(candidate);
    while (cur.has_value()) {
      if (!is_valid(*cur))
        return false;
      if (*cur == ancestor)
        return true;
      cur = nodes_[cur->index].parent;
    }
    return false;
  }

  auto height_impl(node_id id) const -> std::size_t {
    // DFS computing height: O(size of subtree)
    std::size_t best = 0;
    for (auto c : nodes_[id.index].children) {
      if (!is_valid(c))
        continue;
      best = std::max(best, 1U + height_impl(c));
    }
    return best;
  }
};

} // namespace ds

#endif // !TREE_HPP

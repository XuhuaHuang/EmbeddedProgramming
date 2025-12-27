/**
 * @file tree.hpp
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

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace ds {

/**
 * @brief Error codes for tree operations
 *
 */
struct tree_error {
  tree_error(const tree_error &) = default;
  tree_error(tree_error &&) = default;
  tree_error &operator=(const tree_error &) = default;
  tree_error &operator=(tree_error &&) = default;

  enum class code {
    invalid_node,
    invalid_parent,
    cannot_remove_root,
    would_create_cycle,
    out_of_range
  };

  code c{};
  std::string message{};

  friend auto to_string(const tree_error &e) -> std::string {
    return e.message;
  }
};

template <typename T>
  requires std::default_initializable<T> and std::is_arithmetic_v<T>
class tree final {
public:
  using value_type = T;
  using size_type = std::size_t;

  struct node_id final {
    explicit node_id() = default;
    explicit node_id(std::uint32_t idx, std::uint32_t gen) noexcept
        : index{idx}, generation{gen} {}
    explicit node_id(std::uint32_t index) noexcept
        : index{index}, generation{0} {}

    std::uint32_t index{};
    std::uint32_t generation{};

    explicit constexpr operator bool() const noexcept { return index != 0; }

    explicit constexpr operator std::size_t() const noexcept {
      return static_cast<std::size_t>(index);
    }

    friend constexpr auto operator==(node_id a, node_id b) -> bool = default;
    friend constexpr auto operator!=(node_id a, node_id b) -> bool = default;
    friend constexpr auto operator<=>(node_id a, node_id b) = default;
  };

  struct node_handle final {
    static inline constexpr std::uint32_t invalid_id = 0;

    node_id id{invalid_id};

    friend constexpr bool operator==(node_handle a, node_handle b) noexcept {
      return a.id == b.id;
    }
    friend constexpr bool operator!=(node_handle a, node_handle b) noexcept {
      return !(a == b);
    }
    friend constexpr bool operator<(node_handle a, node_handle b) noexcept {
      return a.id < b.id;
    }

    explicit constexpr operator bool() const noexcept {
      return id != invalid_id;
    }
  };

private:
  struct node final {
    T value{};
    std::optional<node_id> parent{};
    std::vector<node_id> children{};
    std::uint32_t generation{node_handle::invalid_id};
    bool alive{true};
  };

  // index 0 unused so that invalid_id=0 is never a valid node
  std::vector<node> nodes{};
  std::optional<node_id> root{};
  std::vector<std::uint32_t> free_list{};

  tree() = default;
};

} // namespace ds

#endif // !TREE_HPP

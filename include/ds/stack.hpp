#pragma once
#ifndef DS_STACK_HPP
#define DS_STACK_HPP

#include <cstddef>
#include <stdexcept>
#include <utility>

namespace ds {

template <typename value_t>
class stack_t {
private:
  struct node_t {
    value_t value;
    node_t* next;

    template <typename... args_t>
    node_t(node_t* next_node, args_t&&... args)
      : value(std::forward<args_t>(args)...)
      , next(next_node) {}
  };

  node_t*     head = nullptr;
  std::size_t size = 0;

public:
  stack_t() = default;

  ~stack_t() {
    while (head) {
      auto* next = head->next;
      delete head;
      head = next;
    }
  }

  template <typename... args_t>
  void push(args_t&&... args) {
    head = new node_t(head, std::forward<args_t>(args)...);
    ++size;
  }

  void pop() {
    if (empty()) {
      throw std::runtime_error("stack is empty");
    }
    auto* next = head->next;
    delete head;
    head = next;
    --size;
  }

  value_t& top() {
    if (empty()) {
      throw std::runtime_error("stack is empty");
    }
    return head->value;
  }

  const value_t& top() const {
    if (empty()) {
      throw std::runtime_error("stack is empty");
    }
    return head->value;
  }

  bool empty() const noexcept { return size == 0; }

  std::size_t get_size() const noexcept { return size; }
};

} // namespace ds

#endif // !DS_STACK_HPP

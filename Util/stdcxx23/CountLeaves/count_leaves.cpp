/**
 * @file count_leaves.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2022-11-10
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <variant>

struct Leaf {};
/* forward declaration */
struct Node;

using Tree = std::variant<Leaf, Node*>;

struct Node {
    Tree left, right;
};

template <typename... Ts> struct overload : Ts... {
    using Ts::operator()...;
};

int count_leaves(const Tree &tree) {
    return std::visit(overload{
        [](const Leaf &) { return 1; },
        [](this const auto &self, const Node *node) -> int {
            return visit(self, node->left) + visit(self, node->right);
        }
    }, tree);
}

int main(void) {
    // empty main function for the sake of compilation
    return 0;
}

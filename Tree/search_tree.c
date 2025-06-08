/**
 * @file search_tree.c
 * @author Xuhua Huang
 * @brief Binary search tree implementation
 * @version 0.1
 * @date 2025-06-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int          value;
    struct node* left;
    struct node* right;
} node;

/**
 * @brief Recursively searches for a value in a binary search tree (BST).
 *        Assumes the BST property: left < root < right.
 *
 * @param root Pointer to the root node of the tree.
 * @param target The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool search_binary_tree(node* tree, const int value) {
    if (tree == NULL) {
        return false;
    } else if (value < tree->value) {
        return search_binary_tree(tree->left, value);
    } else if (value > tree->value) {
        return search_binary_tree(tree->right, value);
    } else if (value == tree->value) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    return 0;
}

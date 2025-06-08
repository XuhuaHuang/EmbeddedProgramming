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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int          value;
    struct node* left;
    struct node* right;
} node;

node* create_node(int value);

bool insert_node(node** root, int value);
bool search_binary_tree(const node* root, int target);
bool delete_node(node** root, int value);
void inorder_traversal(const node* root);
void preorder_traversal(const node* root);
void postorder_traversal(const node* root);
void free_tree(node* root);
int  compute_height(const node* root);

int main(void) {
    node* root = NULL;

    // Insertion
    insert_node(&root, 50);
    insert_node(&root, 30);
    insert_node(&root, 70);
    insert_node(&root, 20);
    insert_node(&root, 40);
    insert_node(&root, 60);
    insert_node(&root, 80);

    // Traversals
    printf("In-order Traversal   : ");
    inorder_traversal(root);
    printf("\n");

    printf("Pre-order Traversal  : ");
    preorder_traversal(root);
    printf("\n");

    printf("Post-order Traversal : ");
    postorder_traversal(root);
    printf("\n");

    // Search
    printf("Search 60: %s\n", search_binary_tree(root, 60) ? "Found" : "Not Found");
    printf("Search 99: %s\n", search_binary_tree(root, 99) ? "Found" : "Not Found");

    // Deletion
    delete_node(&root, 70);
    printf("After deleting 70, In-order Traversal: ");
    inorder_traversal(root);
    printf("\n");

    // Cleanup
    free_tree(root);
    return EXIT_SUCCESS;
}

/**
 * @brief Create a node object
 *
 * @param value The value to assign to the new node.
 * @return node* A pointer to the newly created node.
 */
node* create_node(int value) {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->left  = NULL;
    new_node->right = NULL;
    return new_node;
}

/**
 * @brief Inserts a value into the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 * @param value The value to insert.
 * @return true if the value was inserted successfully, false otherwise.
 */
bool insert_node(node** root, int value) {
    if (root == NULL) {
        return false;
    }

    if (*root == NULL) {
        *root = create_node(value);
        return true;
    }

    if (value < (*root)->value) {
        return insert_node(&((*root)->left), value);
    } else if (value > (*root)->value) {
        return insert_node(&((*root)->right), value);
    }

    return false; // Duplicate value, do not insert
}

/**
 * @brief Searches for a target value in a binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 * @param target The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool search_binary_tree(const node* root, int target) {
    if (root == NULL) {
        return false;
    }

    if (target < root->value) {
        return search_binary_tree(root->left, target);
    } else if (target > root->value) {
        return search_binary_tree(root->right, target);
    }

    return true;
}

/**
 * @brief Finds the node with the minimum value in a binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 * @return node* Pointer to the node with the minimum value, or NULL if the tree is empty.
 */
node* find_min(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

/**
 * @brief Deletes a node with the specified value from the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 * @param value The value to delete.
 * @return true if the node was deleted successfully, false otherwise.
 */
bool delete_node(node** root, int value) {
    if (root == NULL || *root == NULL) {
        return false;
    }

    if (value < (*root)->value) {
        return delete_node(&((*root)->left), value);
    } else if (value > (*root)->value) {
        return delete_node(&((*root)->right), value);
    } else {
        // Node found
        node* temp;
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        } else if ((*root)->left == NULL) {
            temp  = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            temp  = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            temp           = find_min((*root)->right);
            (*root)->value = temp->value;
            delete_node(&((*root)->right), temp->value);
        }
        return true;
    }
}

/**
 * @brief Performs an inorder traversal of the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 */
void inorder_traversal(const node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

/**
 * @brief Performs a preorder traversal of the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 */
void preorder_traversal(const node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

/**
 * @brief Performs a postorder traversal of the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 */
void postorder_traversal(const node* root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
}

/**
 * @brief Frees all nodes in the binary search tree (BST).
 *
 * @param root Pointer to the root node of the tree.
 */
void free_tree(node* root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/**
 * @brief Compute the height of a binary tree.
 *
 * @param root Pointer to the root of the tree.
 * @return Height of the tree in number of edges (−1 for empty tree).
 */
int compute_height(const node* root) {
    if (root == NULL) {
        return -1;
    }

    int left_height  = compute_height(root->left);
    int right_height = compute_height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

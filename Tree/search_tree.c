#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int          value;
    struct node* left;
    struct node* right;
} node;

bool search_binary_tree(node*, const int);

bool search_binary_tree(node* tree, const int value)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (value < tree->value)
    {
        return search(tree->left, value);
    }
    else if (value > tree->value)
    {
        return search(tree->right, value);
    }
    else if (value == tree->value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    return 0;
}

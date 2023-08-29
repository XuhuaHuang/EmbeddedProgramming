// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "binary_tree_node.hpp"

class Solution
{
public:
    void flatten(TreeNode* root)
    {
        TreeNode* now = root;
        while (now)
        {
            if (now->left)
            {
                // find current node's prenode that links to current node's right subtree
                TreeNode* pre = now->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = now->right;
                // use current node's left subtree to replace its right subtree
                // original right subtree is already linked by current node's prenode
                now->right = now->left;
                now->left  = NULL;
            }
            now = now->right;
        }
    }
};

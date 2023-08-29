// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    vector<int> v;

    void postorder(TreeNode* root)
    {
        // design an exit condition
        if (root == nullptr)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        postorder(root);
        return v;
    }
};

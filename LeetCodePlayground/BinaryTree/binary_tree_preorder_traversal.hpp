// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* temp = s.top();
            ans.push_back(temp->val);
            s.pop();
            if (temp->right != NULL)
            {
                s.push(temp->right);
            }
            if (temp->left != NULL)
            {
                s.push(temp->left);
            }
        }
        return ans;
    }
};

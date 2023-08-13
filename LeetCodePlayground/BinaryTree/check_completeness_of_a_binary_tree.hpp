// https://leetcode.com/problems/check-completeness-of-a-binary-tree

#include "binary_tree_node.hpp"

class Solution
{
    template<typename T>
    using queue = std::queue<T>;

public:
    bool isCompleteTree(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        int i = 0, f = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (f && node != NULL)
            {
                return false;
            }
            if (node == NULL)
            {
                f = 1;
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};

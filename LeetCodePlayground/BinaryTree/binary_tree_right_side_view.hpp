// https://leetcode.com/problems/binary-tree-right-side-view

class Solution
{
public:
    inline void solve(TreeNode* root, vector<int>& ans, int level)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        // we entered a new level
        if (level == ans.size())
        {
            ans.push_back(root->val);
        }

        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        int         level = 0;

        solve(root, ans, level);

        return ans;
    }
};

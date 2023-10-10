// https://leetcode.com/problems/separate-the-digits-in-an-array/

class Solution
{
public:
    vector<int> separateDigits(vector<int>& nums)
    {
        vector<int> ans;
        for (const int num : nums)
        {
            string tmp = to_string(num);
            for (const char s : tmp)
            {
                ans.push_back(s - '0');
            }
        }
        return ans;
    }
};

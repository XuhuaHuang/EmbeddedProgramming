// https://leetcode.com/problems/single-number-iii

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        if (nums.size() == 2)
        {
            return nums;
        }
        unordered_map<int, int> mp;
        vector<int>             result{};
        for (int num : nums)
        {
            mp[num]++;
        }
        for (auto key : mp)
        {
            if (key.second == 1)
            {
                result.push_back(key.first);
            }
        }
        return result;
    }
};

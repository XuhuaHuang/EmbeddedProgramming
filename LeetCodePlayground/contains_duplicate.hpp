// https://leetcode.com/problems/contains-duplicate

#include <algorithm>
#include <map>
#include <vector>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::map<int, int> mp;
        for (auto i : nums)
        {
            mp[i]++;
        }

        bool flag = false;
        for (auto i : mp)
        {
            if (i.second >= 2)
            {
                return true;
            }
        }
        return flag;
    }
};

class SortArraySolution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }
        return flag;
    }
};

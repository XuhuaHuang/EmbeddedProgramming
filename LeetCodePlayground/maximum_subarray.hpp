// https://leetcode.com/problems/maximum-subarray

#include <vector>

class Solution
{
public:
    int maxSubArray(const std::vector<int>& nums)
    {
        int curMax     = 0;
        int maxTillNow = INT_MIN;
        for (auto c : nums)
        {
            curMax = max(c, curMax + c);
        }
        maxTillNow = max(maxTillNow, curMax);
        return maxTillNow;
    }
};

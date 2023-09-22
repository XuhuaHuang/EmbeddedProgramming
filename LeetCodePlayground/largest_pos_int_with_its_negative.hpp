// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative

class Solution
{
public:
    int findMaxK(vector<int>& nums)
    {
        int         result = -1;
        vector<int> candidates{};
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == 0)
                {
                    candidates.push_back(abs(nums[i]));
                    break;
                }
            }
        }
        if (candidates.size() >= 1)
        {
            sort(candidates.begin(), candidates.end());
            result = candidates[candidates.size() - 1];
        }

        return result;
    }
};

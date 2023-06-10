// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target)
    {
        std::vector<int> result{-1, -1};
        if (nums.size() == 0)
        {
            return result;
        }
        else if (nums.size() == 1)
        {
            if (nums[0] == target)
            {
                result[0] = 0;
                result[1] = 0;
            }
        }
        else
        {
            int index = nums.size() / 2;
            // find first occurrence
            while (nums[index] > target)
            {
                index /= 2;
            }

            if (nums[index] == target)
            {
                result[0] = index;
            }
            if (nums[index + 1] == target)
            {
                result[1] = index + 1;
            }
            else if (index >= 1 && nums[index - 1] == target)
            {
                result[1] = index;
                result[0] = index - 1;
            }
        }
        return result;
    }
};

// disqualified solution with linear time complexity
class LinearTimeSolution
{
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target)
    {
        std::vector<int> v;
        int              first = -1;
        int              last  = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                first = i;

                break;
            }
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == target)
            {
                last = i;

                break;
            }
        }

        v.push_back(first);
        v.push_back(last);

        return v;
    }
};

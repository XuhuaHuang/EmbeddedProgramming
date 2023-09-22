// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution
{
    template<typename T>
    using vector = std::vector<T>;

public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> ans;
        int         n = numbers.size(), low = 0, high = n - 1;
        while (low < high)
        {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
            {
                ans.push_back(low + 1);
                ans.push_back(high + 1);
                break;
            }
            else if (sum > target)
            {
                high--;
            }
            else
            {
                low++;
            }
        }
        return ans;
    }
};

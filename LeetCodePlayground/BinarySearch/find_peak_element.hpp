// https://leetcode.com/problems/find-peak-element/

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int s   = 0;
        int e   = nums.size() - 1;
        int mid = 0;

        while (s < e)
        {
            mid = s + (e - s) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return s;
    }
};

// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums1.size() == 0 && nums2.size() == 0)
        {
            return 0.0F;
        }
        else if (nums1.size() == 0 && nums2.size() != 0)
        {
            int n = nums2.size();
            return n % 2 ? nums2[n / 2] : (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0;
        }
        else if (nums1.size() != 0 && nums2.size() == 0)
        {
            int n = nums1.size();
            return n % 2 ? nums1[n / 2] : (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
        }
        else if (nums1.size() != 0 && nums2.size() != 0)
        {
            vector<int> v;

            // store the array in the new array
            for (int num : nums1)
                v.push_back(num);

            for (int num : nums2)
                v.push_back(num);

            // sort the array to find the median
            sort(v.begin(), v.end());

            // find the median and return it
            int n = v.size();

            return n % 2 ? v[n / 2] : (v[n / 2 - 1] + v[n / 2]) / 2.0;
        }
        else
        {
            return 0.0F;
        }
    }
};

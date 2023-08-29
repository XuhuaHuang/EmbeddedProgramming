// https://leetcode.com/problems/intersection-of-two-arrays

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, int> m;
        for (int i = 0; i < nums2.size(); i++)
        {
            m[nums2[i]]++;
        }
        set<int> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (m.find(nums1[i]) != m.end())
            {
                v.insert(nums1[i]);
            }
        }

        return {v.begin(), v.end()};
    }
};

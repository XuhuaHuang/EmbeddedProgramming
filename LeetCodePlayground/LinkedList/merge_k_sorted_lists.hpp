// https://leetcode.com/problems/merge-k-sorted-lists

#include "linked_list_node.hpp"

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        map<int, int> mp;
        for (auto& ln : lists)
        {
            while (ln)
            {
                mp[ln->val]++;
                ln = ln->next;
            }
        }
        if (!mp.size())
        {
            return nullptr;
        }
        ListNode* ans = new ListNode();
        ListNode* p   = ans;
        for (auto& v : mp)
        {
            for (int i{}; i < v.second; i++)
            {
                p->next = new ListNode(v.first);
                p       = p->next;
            }
        }
        return ans->next;
    }
};

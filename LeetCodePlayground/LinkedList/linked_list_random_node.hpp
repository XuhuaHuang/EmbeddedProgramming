// https://leetcode.com/problems/linked-list-random-node

#include "linked_list_node.hpp"

class Solution {
    template <typename T>
    using vector = std::vector<T>;

    vector<int> v;
    int         n;

public:
    Solution(ListNode* head) {
        ListNode* ptr = head;
        while (ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        n = v.size();
    }

    int getRandom() {
        static int i = 0;
        if (i == 0) {
            srand(time(NULL));
            i++;
        }
        return v[rand() % n];
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

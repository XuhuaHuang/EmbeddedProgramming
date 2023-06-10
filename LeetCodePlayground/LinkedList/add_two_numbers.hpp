// https://leetcode.com/problems/add-two-numbers

#include "linked_list_node.hpp"

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* temp  = dummy;
        // if the sum of l1->val and l2->val are greater than 10
        // use the carry variable to store the most significant digit
        int carry       = 0;
        while (l1 != nullptr || l2 != nullptr || carry)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            // since 0 <= Node.val <= 9
            // 0 <= sum <= 18
            carry             = sum / 10;
            ListNode* newnode = new ListNode(sum % 10);
            temp->next        = newnode;    // linked the newly constructed node
            temp              = temp->next; // move the temporary pointer
        }
        return dummy->next;
    }
};

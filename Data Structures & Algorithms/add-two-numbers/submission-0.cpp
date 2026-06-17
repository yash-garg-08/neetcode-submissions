/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            int rem = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(rem);
            tail = tail->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr) {
            int l1sum = l1->val + carry;
            int l1rem = l1sum % 10;
            carry = l1sum / 10;
            tail->next = new ListNode(l1rem);
            tail = tail->next;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            int l2sum = l2->val + carry;
            int l2rem = l2sum % 10;
            carry = l2sum / 10;
            tail->next = new ListNode(l2rem);
            tail = tail->next;
            l2 = l2->next;
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        return dummy.next;
    }
};

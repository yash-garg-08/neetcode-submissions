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
    void reorderList(ListNode* head) {
        // 0 ->1 ->2 ->3 ->4 ->5 ->6 ->nullptr
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow ->3

        ListNode* second = slow->next;
        // second ->4
        ListNode* prev = slow->next = nullptr;
        // 0 ->1 ->2 ->3 ->nullptr
        // 4 ->5 -> 6 -> nullptr

        while (second != nullptr) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        // 0 ->1 ->2 ->3 ->nullptr
        // 6 ->5 -> 4 ->nullptr

        ListNode* first = head;
        second = prev;

        // because 2nd part will be always less then or 
        // equal to 1st part
        while(second != nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};

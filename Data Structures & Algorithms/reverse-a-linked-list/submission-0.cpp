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
    ListNode* reverseList(ListNode* head) {
        // previous node of the first node in the LL is nullptr(r)
        ListNode* prevNode = nullptr;
        // current node of the first node in the LL is the head(q)
        ListNode* currNode = head;

        while (currNode != nullptr) {
            // creating a next node(p)
            ListNode* nextNode = currNode->next;
            // reversing the LL
            currNode->next = prevNode;
            // move the prev node to current node
            prevNode = currNode;
            // move the curren node to next node
            currNode = nextNode;
        }
        return prevNode;
    }
};

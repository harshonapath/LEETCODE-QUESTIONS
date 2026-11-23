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

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while(true) {

            ListNode* kth = groupPrev;

            // Find kth node
            for(int i = 0; i < k && kth != NULL; i++) {
                kth = kth->next;
            }

            // Less than k nodes remaining
            if(kth == NULL) {
                break;
            }

            ListNode* groupNext = kth->next;

            // Reverse k nodes
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext) {

                ListNode* temp = curr->next;

                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group
            ListNode* temp = groupPrev->next;

            groupPrev->next = kth;
            groupPrev = temp;
        }

        return dummy->next;
    }
};

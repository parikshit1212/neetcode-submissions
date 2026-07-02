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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* left = head;
        ListNode* right = head;
        // Move second pointer n position ahead in the beginning
        for(int i = 1; i <= n; i++) {
            right = right->next;
        }
        if (right == NULL) {
            // we need to delete the first node i.e head
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        // now move both left and right till right reaches the end
        while(right->next != NULL) {
            left = left->next;
            right = right->next;
        }
        // Now left is standing at the prev pos of the node to be deleted
        ListNode* temp = left->next;
        left->next = left->next->next;
        delete temp;
        return head;
    }
};

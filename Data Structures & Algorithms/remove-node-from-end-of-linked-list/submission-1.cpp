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
        if (head == NULL) return head;
        if (head->next == NULL) {
            delete head;
            return NULL;
        }
        int len = lengthOfLL(head);
        int nodeFromStart = len - n + 1;
        if (nodeFromStart == 1) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        ListNode* curr = head;
        int idx = 0;
        while(idx < nodeFromStart) {
            idx++;
            if (idx == nodeFromStart - 1) {
                ListNode* newNextNode = curr->next->next;
                delete curr->next;
                curr->next = newNextNode;
                break;
            }
            curr = curr->next;
        }
        return head;
    }

private: 
    int lengthOfLL(ListNode* head) {
        int len = 0;
        ListNode* curr = head;
        while(curr != NULL) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};

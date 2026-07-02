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
        int counter = 0;
        return deleteNthNodeFromEnd(head, n, counter);
    }

private:
    ListNode* deleteNthNodeFromEnd(ListNode* head, int n, int &counter) {
        if (head == NULL) return NULL;
        ListNode* nextNode = deleteNthNodeFromEnd(head->next, n, counter);
        counter++;
        if (counter == n) {
            // this is the node to be deleted
            delete head;
            return nextNode;
        }
        head->next = nextNode;
        return head;
    }
};

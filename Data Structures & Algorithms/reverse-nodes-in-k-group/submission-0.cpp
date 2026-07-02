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
        if (head == NULL) return head;
        if (k == 1) return head;

        // Check if this list consist of k nodes or not
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL) {
            count++;
            if (count == k) {
                break;
            }
            curr = curr->next;
        }
        if (count < k) return head;
        // Otherwise sort this
        ListNode* nextPartHead = curr->next;
        curr->next = NULL;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp != NULL) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        // prev is newHead
        head->next = reverseKGroup(nextPartHead, k);
        return prev;
    }
};
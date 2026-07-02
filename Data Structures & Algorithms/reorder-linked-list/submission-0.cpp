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
        if (head == NULL || head->next == NULL) return;
        ListNode* middleNode = middleOfList(head);
        ListNode* reverseSecondHalfHead = reverse(middleNode->next);
        middleNode->next = NULL;

        // Now we have 2 linked list head and reverseSecondHalfHead and we have to merge them 1 by 1 element
        ListNode* first = head;
        ListNode* second = reverseSecondHalfHead;
        while(second != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }

private:

    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* nextNode = head->next;
        ListNode* newHead = reverse(head->next);
        nextNode->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* middleOfList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

};

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
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(curr1 != NULL && curr2 != NULL) {
            int data = curr1->val + curr2->val + carry;
            carry = data/10;
            int value = data % 10;
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1 != NULL) {
            int data = curr1->val + carry;
            int value = data % 10;
            carry = data/10;
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = temp->next;
            curr1 = curr1->next;
        }

        while(curr2 != NULL) {
            int data = curr2->val + carry;
            int value = data % 10;
            carry = data/10;
            ListNode* newNode = new ListNode(value);
            temp->next = newNode;
            temp = temp->next;
            curr2 = curr2->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            temp->next = newNode;
        }
        return dummyNode->next;
    }
};

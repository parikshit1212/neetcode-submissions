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
private:

    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        while(list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                ListNode* nextNode = list1->next;
                curr->next = list1;
                list1 = nextNode;
            } else {
                ListNode* nextNode = list2->next;
                curr->next = list2;
                list2 = nextNode;
            }
            curr = curr->next;
        }

        if (list1) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummyHead->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];

        ListNode* prev = NULL;
        for(int i = 0; i < lists.size(); i++) {
            prev = mergeLists(prev, lists[i]);
        }
        return prev;
    }
};

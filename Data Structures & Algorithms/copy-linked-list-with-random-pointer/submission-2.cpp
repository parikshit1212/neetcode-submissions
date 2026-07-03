/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // insert new nodes of the list inbetween the current list
        if (head == NULL) return head;
        Node* curr = head;
        while(curr != NULL) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Now we have inserted new list inbetween nodes of existing list
        // connect random pointers
        curr = head;
        Node* temp = curr->next;

        while(curr != NULL) {
            temp->random = curr->random == NULL ? NULL : curr->random->next;
            curr = temp->next;
            if (curr == NULL) {
                break;
            } else {
                temp = curr->next;
            }
        }

        // now detach 
        Node* dummyHead = new Node(-1);
        curr = head;
        temp = head->next;
        dummyHead->next = temp;

        while(curr != NULL) {
            curr->next = temp->next;
            curr = curr->next;
            if (curr) {
                temp->next = curr->next;
                temp = temp->next;
            } else {
                temp->next = NULL;
                break;
            }
        }
        return dummyHead->next;
    }
};

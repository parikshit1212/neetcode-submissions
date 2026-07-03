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
        unordered_map<Node*, Node*> mp;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        Node* temp = head;
        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            curr->next = newNode;
            curr = curr->next;
            mp[temp] = newNode;
            temp = temp->next;
        }

        // we have created a list with next pointers, now iterate again and connect random pointers
        temp = head;
        curr = dummy->next;
        while(temp != NULL) {
            Node* randomPointer = temp->random;
            if (randomPointer) {
                Node* nodeForRandomPointer = mp[randomPointer];
                curr->random = nodeForRandomPointer;
            } else {    
                curr->random = randomPointer;
            }
            curr = curr->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};

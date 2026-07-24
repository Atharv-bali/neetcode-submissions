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
        if(head == NULL)
            return head;
        unordered_map<Node*,Node*> mpp;
        Node* oldTemp = head;
        Node* newHead = new Node(oldTemp->val);
        mpp[head] = newHead;
        Node* newTemp = newHead;
        oldTemp = oldTemp->next;
        while(oldTemp!=NULL) {
            Node* copy = new Node(oldTemp->val);
            newTemp->next = copy;
            newTemp = newTemp->next;
            mpp[oldTemp] = newTemp;
            oldTemp = oldTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;
        while(oldTemp!=NULL) {
            newTemp->random = mpp[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};

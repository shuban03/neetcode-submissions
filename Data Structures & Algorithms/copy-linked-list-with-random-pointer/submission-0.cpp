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
        unordered_map<Node*,Node*> oldandcopy;
        oldandcopy[NULL]=NULL;

        Node* curr=head;
        while(curr){
            Node* copy=new Node(curr->val);
            oldandcopy[curr]=copy;
            curr=curr->next;
        }

        curr=head;
        while(curr){
            Node* copy=oldandcopy[curr];
            copy->next=oldandcopy[curr->next];
            copy->random=oldandcopy[curr->random];
            curr=curr->next;
        }
        return oldandcopy[head];
    }
};

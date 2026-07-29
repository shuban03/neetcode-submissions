/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> oldToNew;
        return dfs(node,oldToNew);
    }

    Node* dfs(Node* node,unordered_map<Node*,Node*>& oldToNew){
        //if node is null
        if(node==nullptr){
            return nullptr;
        }

        //if node already exists dont create again, just return it
        if(oldToNew.count(node)){
            return oldToNew[node];
        }

        //create the copy node and add to map
        Node* copy = new Node(node->val);
        oldToNew[node]=copy;
        
        //copy all the neighbors of the node
        for(Node* nei: node->neighbors){
            copy->neighbors.push_back(dfs(nei,oldToNew));
        }
        return copy;
    }
};
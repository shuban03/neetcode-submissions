/*
Definition for a Node.
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

        // Map to store: Original Node -> Cloned Node
        map<Node*, Node*> oldToNew;

        // Start DFS from the given node
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {

        // If graph is empty, return NULL
        if (node == NULL) {
            return NULL;
        }

        // If node is already cloned, return its copy
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a new copy of the current node
        Node* copy = new Node(node->val);

        // Save the mapping before visiting neighbors
        oldToNew[node] = copy;

        // Clone all neighbors one by one
        for (Node* nei : node->neighbors) {

            //copy all his neighbors
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        // Return the cloned node
        return copy;
    }
};
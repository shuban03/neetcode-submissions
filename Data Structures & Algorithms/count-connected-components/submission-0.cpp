class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        // Adjacency list to represent the graph
        vector<vector<int>> adj(n);

        // Keeps track of visited nodes
        vector<bool> visit(n, false);

        // Build the adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);   // Undirected graph
        }

        int res = 0;   // Stores number of connected components

        // Traverse every node
        for (int node = 0; node < n; ++node) {

            // If node is not visited, we found a new component
            if (!visit[node]) {

                // Visit every node in this component
                dfs(adj, visit, node);

                // Increase component count
                res++;
            }
        }

        return res;
    }

private:

    // DFS visits every node connected to 'node'
    void dfs(const vector<vector<int>>& adj,vector<bool>& visit,int node) {

        // Mark current node as visited
        visit[node] = true;

        // Visit all neighbours
        for (int nei : adj[node]) {

            // Visit only unvisited neighbours
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }
};
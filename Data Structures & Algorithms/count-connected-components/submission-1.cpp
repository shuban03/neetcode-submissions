class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);

        // Build the adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);   // Undirected graph
        }

        int res = 0;  

        // Traverse every node
        for (int node = 0; node < n; ++node) {

            // If node is not visited, we found a new component
            if (!visit[node]) {
                // Visit every node in this component
                dfs(adj, visit, node);
                res++;
            }
        }

        return res;
    }

private:
    void dfs(const vector<vector<int>>& adj,vector<bool>& visit,int node) {

         visit[node] = true;
         for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }
};
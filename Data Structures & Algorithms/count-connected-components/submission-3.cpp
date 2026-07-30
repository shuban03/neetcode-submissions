class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,0);

        for(auto edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int res=0;

        for(int node=0;node<n;node++){
            if(!visited[node]){
                dfs(graph,visited,node);
                res++;
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& graph,vector<bool>& visited,int node){
        visited[node]=1;
        for(int next:graph[node]){
            if(!visited[next]){
                dfs(graph,visited,next);
            }
        }
    }
};

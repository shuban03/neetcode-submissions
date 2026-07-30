class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int> indegree(numCourses,0);

        //build the graph
        for(auto edge : prerequisites){
            int course = edge[0];
            int prereq = edge[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> order;

        //bfs
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            order.push_back(cur);

            for(int next:graph[cur]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }

        //detect cycle
        if(order.size()!=numCourses){
            return {};
        }
        return order;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

      
        for (auto edge : prerequisites) {

            int course = edge[0];   // Course to be taken
            int prereq = edge[1];   // Prerequisite course

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue stores courses that currently have NO prerequisites
        queue<int> q;

        // Push all courses with indegree 0 into queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;

        // Perform BFS (Topological Sort)
        while (!q.empty()) {

            // Take one course
            int curr = q.front();
            q.pop();

            // Successfully completed one course
            completed++;

            for (int next : graph[curr]) {

                indegree[next]--;

            
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return completed == numCourses;
    }
};
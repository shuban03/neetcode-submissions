class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list to store the graph
        // graph[u] = courses that can be taken after completing u
        vector<vector<int>> graph(numCourses);

        // indegree[i] = number of prerequisites needed for course i
        vector<int> indegree(numCourses, 0);

        // Build the graph and calculate indegree
        for (auto edge : prerequisites) {

            int course = edge[0];   // Course to be taken
            int prereq = edge[1];   // Prerequisite course

            // Add edge: prereq -> course
            graph[prereq].push_back(course);

            // Increase prerequisite count of 'course'
            indegree[course]++;
        }

        // Queue stores courses that currently have NO prerequisites
        queue<int> q;

        // Push all courses with indegree 0 into queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Count how many courses we successfully complete
        int completed = 0;

        // Perform BFS (Topological Sort)
        while (!q.empty()) {

            // Take one course
            int curr = q.front();
            q.pop();

            // Successfully completed one course
            completed++;

            // Visit all courses that depend on 'curr'
            for (int next : graph[curr]) {

                // Remove one prerequisite
                indegree[next]--;

                // If all prerequisites are finished,
                // this course becomes available
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        // If every course was completed,
        // then no cycle exists
        return completed == numCourses;
    }
};
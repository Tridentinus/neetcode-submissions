class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        // fill out adjacency list: prereq -> requirer
        for (auto edge : prerequisites) {
            if (edge[1]== edge[0]) return false;
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> Q;
        // seed bfs with all first primary components (indegree = 0)
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i])  {
                Q.push(i);
            }
        }

        if (Q.empty()) return false;
        int sum = 0;
        // begin bfs traversal
        // pop primary components and decrease depenedents
        while (!Q.empty()) {
            int curr = Q.front();
            Q.pop();
            sum++;
            for (auto n: adj[curr]) {
                if (--indegree[n] == 0) {
                    Q.push(n);
                }
            }
        }
        return (sum == numCourses);
    }
};

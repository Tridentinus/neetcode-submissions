class Solution {
public:
    // bool dfs(   unordered_map<int,vector<int>>& adj,
    //             vector<int>& state,
    //             int course) {
    //     // found cycle
    //     if (state[course] == 2) return false;
    //     // avoid retrace
    //     if (state[course] == 1) return true;
        
        

    //     state[course] = 2;
    //     for (auto n: adj[course]) {
    //         if(!dfs(adj,state,n)) return false;
    //     }
    //     // demote to visited
    //     state[course] = 1;
    //     return true;
    // }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
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
                cout << "queued " << i << endl;
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
                    cout << "queued " << n << endl; 
                    Q.push(n);
                }
            }
        }



        return (sum == numCourses);
    }
};

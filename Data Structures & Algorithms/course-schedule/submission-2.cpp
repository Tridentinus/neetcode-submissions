class Solution {
public:
    bool dfs(   unordered_map<int,vector<int>>& adj,
                vector<int>& state,
                int course) {
        // found cycle
        if (state[course] == 2) return false;
        // avoid retrace
        if (state[course] == 1) return true;
        
        

        state[course] = 2;
        for (auto n: adj[course]) {
            if(!dfs(adj,state,n)) return false;
        }
        // demote to visited
        state[course] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> state(numCourses,0);
        // fill out adjacency list: prereq -> requirer
        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        // start dfs from all elements to cover unconnected components
        for (auto [k,v] : adj) {
            if(!dfs(adj,state,k)) return false;
        }

        return true;
    }
};

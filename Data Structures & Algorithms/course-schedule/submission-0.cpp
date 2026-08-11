class Solution {
public:
    bool dfs(int src, 
            unordered_map<int, vector<int>>& adj,    
            unordered_set<int>& path) {
        
        if (path.count(src)) return false;
        if (adj[src].empty()) return true;


        path.insert(src);

        for (auto n : adj[src]) {
            if(!dfs(n,adj,path)) return false;
        }

        path.erase(src);
        adj[src].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        auto & edges = prerequisites;
        unordered_map<int,vector<int>> adj;

        for (int i = 0; i < N; i++) {
            adj[i] = vector<int>();
        }

        for (const auto& e: edges) {
            adj[e[0]].push_back(e[1]);
        }

        unordered_set<int> path;

        for (int i = 0; i < N; i++) {
            if (!dfs(i,adj,path)) return false;
        }
        return true;
    }  
};

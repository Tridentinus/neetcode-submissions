class Solution {
public:

    bool dfs(int crs,  
            unordered_set<int>& path,
            unordered_set<int>& seen,
            vector<int>& topSort, 
            unordered_map<int,vector<int>>& adj) {
        
        
        if (path.count(crs)) return false;
        if (seen.count(crs)) return true;


        path.insert(crs);
        for (auto n : adj[crs]) {
            if (!dfs(n,path,seen,topSort,adj)) return false;
        }
        topSort.push_back(crs);
        seen.insert(crs);
        path.erase(crs);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // alias vars for graph understanding 
        int N = numCourses;
        vector<vector<int>>& edges = prerequisites;

        // init and fill an adjancency list
        unordered_map<int,vector<int>> adj;
        
        for (int i = 0; i < N; i++) {
            adj[i] = vector<int>();
        }

        for (auto e: edges){
            adj[e[0]].push_back(e[1]);
        }

        // begin dfs searching, track cycles with visit set

        unordered_set<int> path;
        unordered_set<int> seen;
        vector<int> topSort;
        for (int i = 0; i < N; i++) {
            if(!dfs(i,path,seen,topSort,adj)) return {};
        }
        // reverse(topSort.begin(),topSort.end());
        return topSort;
    }
};

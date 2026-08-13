class Solution {
public:


    bool dfs(   unordered_map<int,vector<int>>& adj,
                unordered_set<int>& path,
                unordered_set<int>& seen,
                int course) {
        if (path.contains(course)) return false;
        if (seen.contains(course)) return true;


        // cout << "   " << course << endl;
        seen.insert(course);
        path.insert(course);
        


        for (auto n: adj[course]) {
            if(!dfs(adj,path,seen,n)) return false;
        }

        path.erase(course);

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        unordered_set<int> seen;
        unordered_set<int> path;
        // fill out adjacency list: prereq -> requirer
        for (auto edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        for (auto [k,v] : adj) {
            if (seen.contains(k)) continue;
            // cout << "path starting at " << k << endl;
            if(!dfs(adj,path,seen,k)) return false;
        }


        return true;




    }
};

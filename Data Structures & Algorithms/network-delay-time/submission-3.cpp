class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;
        unordered_map<int,int> dists;
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({w, v});
        }
        

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        // seed with k
        minHeap.push({0,k});
        int longest = 0;

        while (!minHeap.empty()) {

            auto [d, n] = minHeap.top();
            minHeap.pop();
            if (dists.contains(n)) continue;

            longest = max(longest,d);
            dists[n] = d;

            for (auto [w,v]: adj[n]) {
                if (!dists.contains(v)) minHeap.push({d+w,v});
            }
            
        }

        if (dists.size() != n) return -1;

        return longest;
        
        

        
        
    }
};

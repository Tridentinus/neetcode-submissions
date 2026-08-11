class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // create adjacency list 

        unordered_map<int, vector<pair<double,int>>> adj;

        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<double,int>>();
        }

        // fill adj list (undirected so include reverse edges)
        for (int i = 0; i < edges.size(); i++) {
            auto e = edges[i];
            adj[e[0]].push_back({succProb[i],e[1]});
            adj[e[1]].push_back({succProb[i],e[0]});
        }


        // maxHeap for finding highest prob next edge
        priority_queue<pair<double,int>> pq;

        unordered_set<int> seen;
        pq.push({1.000,start_node});

        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();

            double prob = edge.first; int dest = edge.second;

            if (seen.count(dest)) continue;

            if (dest == end_node) return prob;

            seen.insert(dest);

            for (auto e: adj[dest]) {
                double p = e.first; int d = e.second;
                if (!seen.count(d)) pq.push({prob*p,d});
            }
        }
        return 0;

    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<pair<int,int>>> adj;

        for (int i =0; i < n; i++) {
            adj[i] = vector<pair<int,int>>();
        }

        for (auto edge: times) {
            adj[edge[0]].push_back({edge[1],edge[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap; 
        unordered_map<int,int> shortest;

        minHeap.push({0,k});
        int longest = 0;
        while (!minHeap.empty()) {
            auto e = minHeap.top();
            minHeap.pop();
            int w1 = e.first; int n1 = e.second;

            // if already in shortest path nodes nothing to do
            if(shortest.count(n1)) continue;

            // otherwise we have a new shortest path
            longest = max(longest,w1);
            shortest[n1] = w1;

            for (auto p: adj[n1]) {
                int dest = p.first; int weight = p.second;
                if (!shortest.count(dest)) minHeap.push({w1+weight,dest});
            }


        }

        cout << shortest.size() << endl;
        return (shortest.size() == n) ? longest : -1;

    }
};

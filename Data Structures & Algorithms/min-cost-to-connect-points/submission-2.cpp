class DSU {
public:
    vector<int> Parent, Size;

    DSU(int n) : Parent(n+1), Size(n+1,1) {
        // every node starts off as own parent
        for (int i = 0; i <= n; ++i) Parent[i] = i;
    }

    int find(int node) {
        // recursively search for parent O(N)
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v) {
        // try and join two nodes
        // if same component (share parent) reject
        // O(N) find
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        // larger component absorbs
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<array<int, 3>> edges;
        // collect all (unique) edges O(N)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }
        // sort all edges O(N^2logN^2) = O(N^2logN)
        sort(edges.begin(), edges.end());
        // track output number
        int res = 0;
        // for each edge attempt to add O(N) per call -> O(N^2) 
        for (auto& [dist, u, v] : edges) {
            if (dsu.unionSets(u, v)) {
                res += dist;
            }
        }
        return res;

    }
};
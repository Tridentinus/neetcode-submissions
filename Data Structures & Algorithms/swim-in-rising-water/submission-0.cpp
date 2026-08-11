class Solution {
public:

    int c2i(pair<int,int> coord, int L) {
        return coord.first * L + coord.second; 
    }
    pair<int,int> i2c(int index, int L) {
        return {index/L, index % L};
    } 
    int swimInWater(vector<vector<int>>& grid) {
        int L  = grid.size();
        int N = L*L;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        pq.push({grid[0][0],0});

        unordered_set<int> seen;

        while(!pq.empty()) {
            auto edge = pq.top();
            pq.pop();

            int time = edge.first; int dest = edge.second;
            if (dest == N-1) return time;

            auto coord = i2c(dest,L);
            int row = coord.first; int col = coord.second;
            for (const auto& dir : directions) {
                int r = row + dir[0]; int c = col + dir[1];
                int d = c2i({r,c},L);
                if (r < 0 || r == L || c < 0 || c == L || seen.count(d)) continue;

                seen.insert(d);
                pq.push({max(time,grid[r][c]),d});
            }
            
        }
        return N;

        
    }
};

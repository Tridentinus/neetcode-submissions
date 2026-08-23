class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        int res = 0;
        queue<pair<int,int>> Q;
        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < M; i++) {
            for (int j = 0; j<N; j++) {
                // fresh islands
                if (grid[i][j]==1) {

                    int area = 0;
                    Q.push({i,j});
                    grid[i][j] = 0;

                    while (!Q.empty()) {
                        area++;
                        auto [r,c] = Q.front();
                        Q.pop();
                        for (auto [dr,dc] :dirs) {
                            int newr = r+dr, newc = c+dc;

                            if (newr < 0 || newc < 0|| newr == M || newc == N || !grid[newr][newc]) continue;

                            Q.push({newr,newc});
                            grid[newr][newc] =0;
                        }
                    }
                    res = max(res,area);
                }
            }
        }

        return res;
        
    }
};

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();

        // scan and add treasure as sources
        queue<pair<int,int>> Q;
        for (int i = 0; i < M; i++) {
            for (int j=0; j< N; j++) {
                if (grid[i][j]==0)  {
                    Q.push({i,j});
                }
            }
        }

        int delta[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int dist =0;
        while (!Q.empty()) {
            int Qlen = Q.size();
            for (int i = 0; i < Qlen; i++) {
                auto [r,c] = Q.front();
                Q.pop();
                // update with length needed to get here
                grid[r][c] = dist;

                for (auto [dr,dc]: delta) {
                    int newr = r+dr, newc = c+dc;
                    if (newr < 0 || newc < 0 || newr == M || newc == N || grid[newr][newc] <= dist) continue;
                    Q.push({newr,newc});
                    // mark this way until processed to avoid double touching
                    grid[newr][newc] = -1;
                }

            }
            dist++;
        }
    }
};

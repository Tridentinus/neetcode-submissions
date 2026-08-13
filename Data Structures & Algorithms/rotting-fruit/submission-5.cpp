class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int R = grid.size();
        int C = grid[0].size();
        int freshCount = 0;
        int rotted = 0;
        queue<pair<int,int>> Q;

        // seed bfs with rot sources
        // establish freshcount
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) freshCount++;
                else if (grid[i][j] == 2) Q.push({i,j});
            }
        }

        if (!freshCount) return 0;
        int deltas[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int time = 0;
        while (!Q.empty()) {
            int Qlen = Q.size();

            for (int i = 0; i < Qlen; i++) {
                auto [r,c] = Q.front();
                Q.pop();
                for (auto [dr,dc] :deltas) {
                    int newr = r+dr, newc = c+ dc;
                    if (newr < 0 || newc < 0 || newr == R || newc == C) continue;
                    if (grid[newr][newc] == 0 || grid[newr][newc] == 2) continue;
                    Q.push({newr,newc});
                    grid[newr][newc] = 2;
                    rotted++;
                }
            }
            time++;
        }
        // cout << freshCount << " " << rotted << endl;
        return (freshCount == rotted) ? time-1 : -1;



        
        
    }
};

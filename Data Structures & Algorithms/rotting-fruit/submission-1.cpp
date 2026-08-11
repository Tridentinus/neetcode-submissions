class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        queue<pair<int,int>> Q;
        
        int fresh = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1) fresh++;
                if (grid[i][j] == 2) Q.push({i,j});
            }
        }
        
        int T = 0;

        vector<pair<int,int>> deltas = {{0,1},{1,0},{0,-1},{-1,0}};

        while (fresh > 0 && Q.size()) {
            int Qlen = Q.size();
            for (int i = 0; i < Qlen; i++) {
                pair<int,int> curr = Q.front();
                Q.pop();


                int r = curr.first; int c = curr.second;

                
                for (auto& d: deltas) {
                    int row = r + d.first;
                    int col = c + d.second;
                    if (min(row,col) <0 || row == R || col == C || grid[row][col] != 1) continue;
                    grid[row][col] = 2;
                    Q.push({row,col});
                    fresh--;
                }
            }
            T++;
        }
        return fresh == 0 ? T : -1;
        

    }
};

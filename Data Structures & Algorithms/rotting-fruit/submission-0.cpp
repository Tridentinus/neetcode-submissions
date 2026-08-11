class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        queue<pair<int,int>> que;
        int time = 0;
        int fresh =0;
        for (int r =0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] ==1) fresh++;
                if (grid[r][c] ==2) que.push({r,c});
            }
        }

        vector<pair<int,int>> direct({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

        while (fresh > 0 && !que.empty()) {
            int qLen = que.size();
            for (int i = 0; i < qLen; i++) {
                pair<int,int> curr = que.front();
                que.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto& dir : direct) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >=0 && row < R && col >=0 && col < C && grid[row][col]==1) {
                        grid[row][col] =2;
                        que.push({row,col});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh==0 ? time : -1;




    }
};

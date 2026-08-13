class Solution {
public:

    int bfs(vector<vector<char>>& grid,int r, int c, int R, int C) {
        if (r < 0 || c<0 || r == R || c == C || grid[r][c] == '0')   {
            return 0;
        }

        queue<pair<int,int>> Q;
        
        // start with src and eliminate backtrack
        Q.push({r,c});
        grid[r][c] = '0';


        int deltas[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        while (!Q.empty()) {
            auto curr = Q.front();
            Q.pop();

            for (auto [dr,dc]: deltas) {
                int newr = curr.first+dr, newc = curr.second+dc;
                if (min(newr,newc) < 0 || newr == R || newc == C || grid[newr][newc] == '0') continue;
                Q.push({newr,newc});
                // mark for dedupe
                grid[newr][newc] = '0';
            }
        }



        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int sum = 0;
        for (int i = 0; i < R; i++) {
            for (int j=0; j < C; j++) {
                sum+=bfs(grid,i,j,R,C);
            }
        }

        return sum;
    }
};

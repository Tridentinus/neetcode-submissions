class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c,set<pair<int,int>>& seen){
        int R = grid.size();
        int C = grid[0].size();

        if (r < 0 || r == R || c < 0 || c == C || !grid[r][c] || seen.count({r,c})) return 0;

        int count = 1;
        seen.insert({r,c});
        count += dfs(grid,r+1,c,seen);
        count += dfs(grid,r-1,c,seen);
        count += dfs(grid,r,c+1,seen);
        count += dfs(grid,r,c-1,seen);

        return count;


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int maxArea = 0;
        set<pair<int,int>> seen{};
        for (int r = 0; r < R; r++) {
            for (int c =0; c<C; c++) {
                if (grid[r][c] && !seen.count({r,c})) { 
                    int area = dfs(grid,r,c,seen);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>> & grid,int r,int c, set<pair<int,int>> & visited) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == '0' || visited.count({r,c})) {
            return;
        }

        visited.insert({r,c});
        dfs(grid, r + 1, c+0,visited);
        dfs(grid, r - 1, c+0,visited);
        dfs(grid, r + 0, c+1,visited);
        dfs(grid, r + 0, c-1,visited);
        return;


    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int count = 0;
        set<pair<int,int>> visited{};
        for (int r = 0; r < R; r++) {
            for (int c =0; c<C; c++) {
                if (grid[r][c] == '1' && !visited.count({r,c})) {
                    dfs(grid,r,c,visited);
                    // for (auto e: visited) {
                    //     cout << e.first << " " << e.second << endl;
                    // }
                    // cout << endl;
                    count++;
                }
            }
        }
        
        return count;
    }
};

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c, set<pair<int,int>>& visited) {
        int ROWS = grid.size(), COLS = grid[0].size();
        // not a novel piece of curr island do not mark
        if (min(r, c) < 0 || r == ROWS || c == COLS ||
            visited.count({r,c}) || grid[r][c]=='0') {
            return;
        }

        visited.insert({r,c});

        dfs(grid, r + 1, c, visited);
        dfs(grid, r - 1, c, visited);
        dfs(grid, r, c + 1, visited);
        dfs(grid, r, c - 1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size();
        int M = grid[0].size();

        int count = 0;
        set<pair<int,int>> visited;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if ((grid[i][j] == '1') && !(visited.count({i,j}))) {
                    count++;
                }

                dfs(grid, i,j,visited);
            }
        }

        return count;
        
    }
};

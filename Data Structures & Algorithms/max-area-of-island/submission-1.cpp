class Solution {
public:



    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited) {
        int R = grid.size();
        int C = grid[0].size();
        cout << "dfs: " << r << " " << c << endl;
        if (min(r,c) < 0 || r == R || c == C || !grid[r][c] || visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        return 1 + dfs(grid,r+1,c,visited) + 
                    dfs(grid,r-1,c,visited) + 
                    dfs(grid,r,c+1,visited) + 
                    dfs(grid,r,c-1,visited);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int M = grid.size();
        int N = grid[0].size();

        vector<vector<bool>> visited(M,vector<bool>(N,false));

        int best = 0;

        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                cout << "main: " << r << " " << c << endl;
                if (grid[r][c] && !(visited[r][c])) {
                    best = max(best, dfs(grid,r,c,visited));
                }
            }
        }

        return best;


    }
};

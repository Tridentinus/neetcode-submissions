class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int N = grid.size();
        vector<vector<bool>> seen(N,vector<bool>(N));
        queue<pair<int,int>> que;

        //start from top left
        que.push({0,0}); // its next to be popped/examined
        seen[0][0] =1; // cant be popped by someone else
        int length = 1;

        while (!que.empty()) {
            int qLength = que.size();
            for (int i = 0; i < qLength; i++) {
                pair<int, int> curPair = que.front();
                que.pop();
                int r = curPair.first; int c = curPair.second;
                if (r == N-1 && c == N-1) return length;
            
                int neighbors[8][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c},{r-1,c-1},{r-1,c+1},{r+1,c-1},{r+1,c+1}};

                for (int j = 0; j < 8; j++) {
                    int newR = neighbors[j][0], newC = neighbors[j][1];
                    if (min(newR, newC) < 0 || newR == N || newC == N
                        || seen[newR][newC] || grid[newR][newC]) {
                        continue;
                    }
                    que.push(pair<int, int>(newR, newC));
                    seen[newR][newC] =1;
                }
            }
            length++;
        }
        return -1;


    }
};
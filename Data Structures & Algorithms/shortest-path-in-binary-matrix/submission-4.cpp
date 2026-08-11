class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        int N = grid.size();
        vector<vector<bool>> visited(N,vector<bool>(N));

        queue<pair<int,int>> Q;

        Q.push({0,0});
        visited[0][0] = true;


        int length =1;


        while (Q.size()) {
            int Qlen = Q.size();
            for (int i = 0; i < Qlen; i++) {
                pair<int,int> curPair = Q.front();
                Q.pop();

                int r = curPair.first; int c = curPair.second;
                if (r == N - 1 && c == N - 1) {
                    return length;
                }

                int neighbors[8][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r + 1, c+1},{r - 1, c-1},{r - 1, c+1},{r +1, c-1}};\

                for (int j = 0; j < 8; j++) {
                    int newR = neighbors[j][0]; int newC = neighbors[j][1];
                    if (min(newR, newC) < 0 || newR == N || newC == N
                        || visited[newR][newC] || grid[newR][newC]) {
                        continue;
                    }
                    Q.push({newR,newC});
                    visited[newR][newC] = true;
                }
                
            }
            length++;
        }

 
        return -1;
        
           
    }
};
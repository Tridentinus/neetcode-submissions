class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;

        int N = grid.size();

        // seen store (uin8_t for space)
        vector<vector<uint8_t>> visited(N, vector<uint8_t>(N));

        // working set queue
        queue<pair<int,int>> Q;

        // seed with top left
        Q.push({0,0});
        visited[0][0] =1;
        int len = 1;
        

        while (Q.size()) {
            // store because we only want to pop this layer's nodes
            int Qlen = Q.size();
            for (int i = 0; i < Qlen; i++) {
                pair<int,int> curr = Q.front();
                Q.pop();
                int r = curr.first, c = curr.second;
                // if we have found an exit just return length to get there
                if (r == N-1 && c == N-1) return len;
                
                int adj[8][2] = {{r+1,c},   {r-1,c},    {r,c+1},    {r,c-1},
                                 {r+1,c+1}, {r-1,c-1},  {r+1,c-1},  {r-1,c+1}};

                for (auto a : adj) {
                    int newR = a[0], newC = a[1];
                    if (min(newR, newC) < 0 || newR == N || newC == N
                        || visited[newR][newC] || grid[newR][newC]) {
                        continue;
                    }
                            Q.push({newR,newC});
                            visited[newR][newC] = 1;
                    
                    
                }
            }
            len++;
        }

        return -1;
        

        




        

        

        
    }
};
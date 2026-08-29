class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int M = heights.size();
        int N = heights[0].size();
        
        queue<pair<int,int>> Q;
        vector<vector<char>> pMat(M,vector<char>(N,0));

        // seed the pacific expansion
        for (int i = 0; i < M; i++) {
            Q.push({i,0});
            pMat[i][0]=1;
        }
        for (int j = 0; j < N; j++) {
            Q.push({0,j});
            pMat[0][j]=1;

        }

        int deltas[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

        while (Q.size() > 0) {

            auto [r,c] = Q.front();
            Q.pop();

            int height = (r<0 || c<0) ? 0 : heights[r][c];
            for (auto [dr,dc] : deltas) {
                int newr = r + dr; int newc = c+dc;
                if (newr < 0 || newc < 0 || newr == M || newc == N || pMat[newr][newc] == 1|| heights[newr][newc] < height) continue;
                pMat[newr][newc] = 1;
                Q.push({newr,newc});
            }
        }
        vector<vector<char>> aMat(M,vector<char>(N,0));



        // seed the atlantic expansion
        for (int i = 0; i < M; i++) {
            Q.push({i,N-1});
            aMat[i][N-1]=1;

        }
        for (int j = 0; j < N; j++) {
            Q.push({M-1,j});
            aMat[M-1][j]=1;

        }


        while (Q.size() > 0) {
            auto [r,c] = Q.front();
            Q.pop();

            int height = (r==M || c==N) ? 0 : heights[r][c];
            for (auto [dr,dc] : deltas) {
                int newr = r + dr; int newc = c+dc;
                if (newr < 0 || newc < 0 || newr == M || newc == N || aMat[newr][newc]==1 || heights[newr][newc] < height) continue;
                aMat[newr][newc]=1;
                Q.push({newr,newc});
            }
        }
        vector<vector<int>> res;
        for (int i = 0; i < M; i++) {
            for (int j=0; j<N;j++) {
                if (aMat[i][j] && pMat[i][j]) res.push_back({i,j});
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int R = image.size();
        int C = image[0].size();
        queue<pair<int,int>> Q;
        Q.push({sr,sc});
        int scolor = image[sr][sc];
        image[sr][sc] = color;

        int dirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        while (!Q.empty()) {
            auto [r,c] = Q.front();
            Q.pop();

            for (auto d: dirs) {
                int ar = r+d[0], ac = c + d[1];
                if (ar < 0 || ac < 0 || ar == R || ac == C || image[ar][ac] != scolor || image[ar][ac] == color) continue;
                Q.push({ar,ac});
                image[ar][ac] = color;
            }
            
        }
        return image;
    }
};
class Solution {
public:

    void dfs(vector<vector<int>>& image, int R, int C, int sr, int sc, int color, int scolor) {
        // OOB check
        if (sr < 0 || sr == R || sc < 0 || sc == C) return;
        if (image[sr][sc] != scolor || image[sr][sc] == color) return;

        image[sr][sc] = color;

        dfs(image, R, C, sr+1, sc, color, scolor);
        dfs(image, R, C, sr, sc+1, color, scolor);
        dfs(image, R, C, sr-1, sc, color, scolor);
        dfs(image, R, C, sr, sc-1, color, scolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int R = image.size();
        int C = image[0].size();
        
        dfs(image, R,C, sr,sc,color,image[sr][sc]);
        return image;
    }
};
class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix)  {
        int M = matrix.size();
        int N = matrix[0].size();

        sums.assign(M+1, vector<int>(N+1,0));
        
        for (size_t j = 0; j < N; j++) {
            for (size_t i = 0; i < M; i++) {
                sums[i+1][j+1] = matrix[i][j] + sums[i+1][j] + sums[i][j+1] - sums[i][j];
            }
        } 
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
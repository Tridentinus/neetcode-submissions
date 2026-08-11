class NumMatrix {
private:
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        sums.resize(M+1);
        for (auto& r: sums) {
            r.resize(N+1);
        }
        
        // accumulate row sums
        for (size_t i = 0; i < M; i++) {
            int rsum = 0;
            for (size_t j = 0; j < N; j++) {
                rsum+= matrix[i][j];
                sums[i+1][j+1] = rsum;
            }
        }
        //

        for (size_t j = 0; j < N; j++) {
            int csum = 0;
            for (size_t i = 0; i < M; i++) {
                csum+= sums[i+1][j+1];
                sums[i+1][j+1] = csum;
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
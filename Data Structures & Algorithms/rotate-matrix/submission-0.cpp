class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        // two steps 
        // 1. flip along horizontal access 
        // 2. transpose

        // flip -> perform ~N*N/2 swaps (top half with bottom half)
        for (int i = 0; i < N/2; i++) {
            int mirror = N - 1 - i;
            for (int j = 0; j < N; j++) {
                swap(matrix[i][j],matrix[mirror][j]);
            }
        }

        // transpose -> perform N*N/2 swap (UR with BL)
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // for (auto r : matrix) {
        //     cout <<endl;
        //     for (auto c: r) {
        //         cout << c <<" "; 
        //     }
        // }
        
    }
};

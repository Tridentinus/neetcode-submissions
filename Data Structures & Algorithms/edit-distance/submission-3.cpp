class Solution {
public:
    int minDistance(string word1, string word2) {
        // idea is similar to LCS

        int M = word1.length(); int N = word2.length();

        if (!M || !N) return max(M,N);
        // start with O(NM) dp for now
        vector<vector<int>> dp(M+1,vector<int>(N+1,201)); // fill with max for minimum ops

        dp[0][0] = 0;
        // base case!
        for (int i = 1; i < M+1; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j < N+1; j++) {
            dp[0][j] = j;
        }


        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                //match case no added work
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 0;
                }
                // insert/delete case
                else {
                    dp[i+1][j+1] = min(dp[i+1][j],dp[i][j+1]) +1;
                    // replace case
                    if (i == j) dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+1);
                }
                
            }
        }
        // for (auto v: dp) {
        //     for (auto e: v) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }




        return dp[M][N];
    }
};

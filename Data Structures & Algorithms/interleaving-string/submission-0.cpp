class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // my idea is the following
            // if s1[i] matches check if |s3| -1 matches using s1[0:i-1]
            // if s2[j] matches check if |s3| -1 matches using s2[0:j-1]
            // if neither match string false


        int M = s1.size(); int N = s2.size(); int T = s3.size();

        if (T != M+N) return false;

        int S1 = reduce(s1.begin(),s1.end(),0);
        int S2 = reduce(s2.begin(),s2.end(),0);
        int S3 = reduce(s3.begin(),s3.end(),0);

        if (S1 + S2 != S3) return false;

        vector<vector<bool>> dp(M+1,vector<bool>(N+1,false));

        //base case UL 
        dp[0][0] = true;

        // base case top row (interleave s2 with _)
        for (int i = 1; i < M+1; i++) {
            dp[i][0] = (s1[i-1] == s3[i-1]) && (dp[i-1][0]); 
        }
        
        // base case top row (interleave s1 with _)
        for (int j = 1; j < N+1; j++) {
            dp[0][j] = (s2[j-1] == s3[j-1]) && (dp[0][j-1]); 
        }

        //main execution
        for (int i = 1; i < M+1; i++) {
            for (int j = 1; j < N+1; j++) {
                dp[i][j] = (s1[i-1] == s3[i+j-1]) && (dp[i-1][j]) || (s2[j-1] == s3[i+j-1]) && (dp[i][j-1]); 
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

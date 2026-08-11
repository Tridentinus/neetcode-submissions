class Solution {
public:
    int numDistinct(string s, string t) {
        int M = s.size(); int N = t.size();

        vector<vector<int>> dp (M+1,vector<int>(N+1));
        

        // base case for _ from _
        dp[0][0] = 1;

        // base cases form t from _
        for (int j = 1; j < N+1; j++) {
            dp[0][j] = 0;
        }
        
        //base cases form _ from s
        for (int i = 1; i < M+1; i++) {
            dp[i][0] = 1;
        }

        // main execution

        for (int i = 1; i < M+1; i++) {
            for (int j = 1; j< N+1; j++) {
                // not enough chars
                if (i < j) dp[i][j] =0; 
                // no chars to spare
                else if (i == j) dp[i][j] = (s[i-1] == t[j-1])&& (dp[i-1][j-1] == 1);

                // spare chars
                else {
                    // in match case, we check how many ways we could already form w/o new s char 
                    if (s[i-1] == t[j-1]) {
                        if (dp[i-1][j]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                        //if couldnt form without we its the no spare case from before
                        else dp[i][j] = dp[i-1][j-1];
                    }
                    // in mismatch we have only one option, exclude
                    else {
                        dp[i][j] = dp[i-1][j];
                    }
                }            

                
            }   
        }

        for (auto v: dp) {
            for (auto e: v) {
                cout << e << " ";
            }
            cout << endl;
        }
        return dp[M][N];
    }
};

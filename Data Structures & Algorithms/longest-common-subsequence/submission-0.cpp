class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // what is the invariant 
        // at any given point we have remaining substrs s1 and s2 and the previosly best obtained LCS of prior
        // LCS() = prior + LCS(sub1,sub2)
        // we know all letters must be compared so O(nm) is natural time complexity bound to start
        int m = text1.size();
        int n = text2.size();

        // to hold our solutions we will start with naive O(nm)
        vector<vector<int>> dp(m+1,vector<int>(n+1,0)); // zero padded for bases cases

        // main idea, if head matches for sub1,sub2 we can advance into both with +1 increment
            //otherwise we advance into both paths. 
            //since this is dp we must have precomputed some prior 
            // so arbitrarily expand row by row unilaterally so we can refer to a prior in match case
            // and maximal LCS of current path to subproblem otherwise
        // for every representative row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (text1[i] == text2[j]){
                    // match case advance both with increment
                    dp[i+1][j+1] = dp[i][j] +1;
                }
                else {
                    // best solution that got us here with last advance from str1 or str2
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }

        return dp[m][n];

    }
};

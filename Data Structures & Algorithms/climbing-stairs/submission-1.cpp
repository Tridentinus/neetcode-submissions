class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2) return n;
        vector<int> dp;
        dp.reserve(n);
        dp.push_back(1);
        dp.push_back(2);

        for (int i =2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        
        }

        return dp[n-1];
    }
};

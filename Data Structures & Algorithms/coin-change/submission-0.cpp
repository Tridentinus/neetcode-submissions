class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0] =0;
        for (int t = 1; t <= amount; t++) {
            dp[t] = amount+1;
            for (const auto c: coins) {
                if (c > t) continue;
                dp[t] = min(dp[t], dp[t-c]+1);
            }
            
        }

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};

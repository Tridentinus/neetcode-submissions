class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();
        if (n==1) return nums[0];
        dp.reserve(n);
        for (int i =0; i < n; i++) {
            if (i == 0) {
                dp[i] = nums[i];
            } else if (i==1) {
                dp[i] = max(nums[i],dp[i-1]);
            }
            else {
                dp[i] = max(nums[i] + dp[i-2],dp[i-1]);
            }
        }
        return max(dp[n-1],dp[n-2]);
    }
};

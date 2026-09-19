class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() ==2) return min(cost[0],cost[1]);

        pair<int,int> dp;
        dp.first = cost[0];
        dp.second = cost[1];

        for (int i = 2; i < cost.size(); i++) {
            auto [f,s] = dp;
            dp.first = dp.second;
            dp.second = min(f,s)+cost[i];
        }

        return min(dp.first,dp.second);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // cost = [1,2,3] 
        // two outcomes @ [1,2]: [1,2]
        // encounter 3: two ways i can arrive at 3, 1 + 3 or 2 + 3: [4,5] -> 4 dominates : [1,2,4] return 4
        

        // dp = [1,2]
        // encounter 1: [2,3]: 2
        // dp = 1,2,2
        // encounter 2: [4,4]: 4
        // dp = 1,2,2,4
        // encounter 1: [3,5]: 3
        // dp = 1,2,2,4,3
        // encounter 1: [5,4]: 4
        // dp = 1,2,2,4,3,4
        // encounter 1: [4,5]: 4
        // return 4
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

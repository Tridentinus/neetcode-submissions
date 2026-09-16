class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        
        pair<int,int> dp;
        dp.first=1;
        dp.second=2;
        for (int i = 2; i < n; i++) {
            auto [f,s] = dp;
            dp.first = s;
            dp.second = f+s;
        }
        return dp.second;

    }
};

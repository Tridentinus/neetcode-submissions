class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2) return n;
        pair<int,int> dp;
        dp.first = 1;
        dp.second = 2;

        for (int i =2; i < n; i++) {
            int way = dp.first + dp.second;
            dp.first = dp.second;
            dp.second = way;
        }

        return dp.second;
    }
};

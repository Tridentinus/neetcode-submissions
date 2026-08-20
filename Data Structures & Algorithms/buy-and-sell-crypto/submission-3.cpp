class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int best = 0;
        int L =0;
        int sell = 0;
        while (L < prices.size()-1) {
            int buy = prices[L];
            int R = L+1;
            while (R < prices.size() && prices[R] >= buy ) {
                best = max(best, prices[R]-buy);
                R++;
            }
            if (R == prices.size()) return best;
            L = R;
        }


        return best;



    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // cannot profit on one day
        if (prices.size() < 2) return 0;
        // track best margin 
        int best = 0;
        
        int L =0;
        while (L < prices.size()-1) {
            int R = L+1;
            // continue updating best trade with curr buy price 
            while (R < prices.size() && prices[R] >= prices[L] ) {
                best = max(best, prices[R]-prices[L]);
                R++;
            }
            if (R == prices.size()) return best;
            // when find lower buy price continue from that
            L = R;
        }

        return best;



    }
};

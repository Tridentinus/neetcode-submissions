class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // prices = [10,1,5,6,7,1]
        // i,j = 0
        // best = 0
        // 1
        int N = prices.size();
        int i = 0; int j = 1;
        int best =0;
        while (i < N && j < N)  {
            
            while (i < N && j < N && prices[i] < prices[j] ) {
                best = max(best,prices[j] -prices[i]);
                j++;
            }
            i = j;
            j = i+1;
        }
        return best;
    }
};

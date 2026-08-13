class Solution {
public:
    bool verify(int k, const auto & piles,int h) {
        int sum = 0;
        for (auto p: piles) {
            int div = p/k;
            int rem = p%k;
            if (rem) div++;
            sum+=  div;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int S = 1, E = *max_element(piles.begin(), piles.end());
        int minK = -1;
        while (S <= E) {
            int M = S + (E-S)/2;
            if (verify(M,piles,h)) {
                E = M-1;
                minK = M;
            }
            else S = M+1;
        }

        return minK;
    }
};

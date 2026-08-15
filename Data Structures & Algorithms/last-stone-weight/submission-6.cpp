class Solution {
public:
    // bucket sort
    int lastStoneWeight(vector<int>& stones) {
        // get largest element for range O(N)
        int maxW = *std::max_element(stones.begin(), stones.end());

        // populate buckets T: O(N) S: O(W)

        vector<int> buckets(maxW+1,0);
        for (auto s: stones) {
            buckets[s]++;
        }


        // destroy phase
        // stones=[2, 7, 4, 1, 8, 1]
        // buckets = [0,2,1,0,1,0,0,1,1] step = 0
        // buckets = [0,2,1,0,1,0,0,0,0] step = 1
        // buckets = [0,2,0,0,0,0,0,0,0] step = 2
        // buckets = [0,0,0,0,0,0,0,0,0] step = 3

        int s1 = maxW, s2 = maxW;
        while (s1 > 0) {
            if (buckets[s1] == 0) {s1--; continue;}


            if (buckets[s1] %2 == 0) {
                buckets[s1] = 0;
            }
            else {
                s2 = s1-1;
                while (s2 >= 0 && buckets[s2] == 0) {
                    s2--;
                }
                if (s2 < 0) return s1;
                buckets[s2]--;
                buckets[s1] = 0;
                buckets[s1-s2]++;
            }
            s1--;
        }

        return s1;



    }
};

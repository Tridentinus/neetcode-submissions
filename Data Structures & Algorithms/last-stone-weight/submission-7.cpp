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
        // T: O(W)
        int s1 = maxW, s2 = maxW;
        while (s1 > 0) {
            // skip over empty weight classes
            if (buckets[s1] == 0) {s1--; continue;}
            // even weight classes go to 0
            if (buckets[s1] %2 == 0) {
                buckets[s1] = 0;
            }
            // odd weight classes look for next heaviest
            else {
                // search for lower weight class
                s2 = s1-1;
                while (s2 >= 0 && buckets[s2] == 0) {
                    s2--;
                }
                // if cant find we have last stone
                if (s2 < 0) return s1;
                // otherwise resolve the fight and add the resultant
                buckets[s2]--;
                buckets[s1] = 0;
                buckets[s1-s2]++;
            }
            // descend the weight classes
            s1--;
        }
        return s1;



    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        vector<vector<int>> freq(nums.size()+1);

        for (auto e: nums) {
            counts[e]++;
        }
        for (const auto& e: counts) {
            freq[e.second].push_back(e.first);
        }


        vector<int> res;
        int count = k;
        for (int i = freq.size() -1; i>0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

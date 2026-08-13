class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        vector<int> res;

        for (auto e: nums) {
            hashMap[e]++;
        }
        vector<pair<int,int>> pairs(hashMap.begin(), hashMap.end());
        sort(pairs.begin(), pairs.end(),[](const auto a, const auto b) {return a.second > b.second;});

        int count = k;
        for (auto& [k,v]: pairs) {
            res.push_back(k);
            count--;
            if (count == 0) break;
        }



        return res;
    }
};

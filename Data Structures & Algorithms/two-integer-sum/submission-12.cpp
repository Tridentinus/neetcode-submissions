class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diffs;
        diffs.reserve(nums.size());
        for (int i = 0; i< nums.size(); i++) {
            auto it = diffs.find(target-nums[i]);

            if (it != diffs.end()) {
               return {it->second,i};
            }

            diffs.emplace(nums[i],i);
            
        }

    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diffs;

        for (int i = 0; i< nums.size(); i++) {
            auto it = diffs.find(target-nums[i]);

            if (it == diffs.end()) {
                diffs.insert({nums[i],i});
            }

            else {
                return vector<int>({it->second,i});
            }
        }

    }
};

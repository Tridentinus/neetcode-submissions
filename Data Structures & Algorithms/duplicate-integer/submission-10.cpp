class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size());
        // T: O(N) M:(N)
        for (int e: nums) {
            // lookup is O(1)
            if(!seen.insert(e).second) return true;
        }

        return false;
    }
};
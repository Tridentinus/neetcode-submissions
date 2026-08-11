class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        // T: O(N) M:(N)
        for (auto const e: nums) {
            // lookup is O(1)
            if (seen.contains(e)) {
                return true;
            }
            // insert is O(1)
            seen.insert(e);
        }

        return false;
    }
};
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;
        unordered_map<int,int> window;
        int L = 0, R = 1;
        window[nums[L]]++;

        // build window
        while (R <= k && R < nums.size()) {
            if (window[nums[R]] > 0) return true;
            window[nums[R]]++;
            R++;
        }

        // slide fixed size window 
        while (R < nums.size()) {
            window[nums[L++]]--;
            if (window[nums[R]] > 0) return true;
            window[nums[R]]++;
            R++;
        }

        return false;
    }
};
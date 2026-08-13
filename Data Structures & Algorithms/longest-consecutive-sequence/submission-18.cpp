class Solution {
public:

    /*
    Plan:

    as we encounter chars we check add them to      
    hashmap with the length of longest preceeding
    subseq seen so far (add entry at n-1). if no 
    such entry exists seed at 1.
    */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int res = 0;
        for (auto n: nums) {
            seen.insert(n);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (seen.contains(nums[i]-1)) continue;

            int target = nums[i];
            int len = 1;
            while (seen.contains(target+1)) {
                len++;
                target++;
            }
            res = max(res,len);
        }

        

        return res;

    }
};

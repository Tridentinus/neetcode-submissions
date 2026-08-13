class Solution {
public:

    /*
    Plan:

    add all seen chars to a set T:O(n) M: O(n)

    iterate over set values T: O(n)
    - when find a value with nothing preceeding walk until no next entry
    - take max of that length with longest so forward_list
    return longest length subseq
    */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int res = 0;
        // note all seen nums
        for (auto n: nums) {
            seen.insert(n);
        }
        
        for (size_t i = 0; i < nums.size(); i++) {
            // if in the middle of a subseq move on
            if (seen.contains(nums[i]-1)) continue;
            // otherwise measure length of the subseq
            int target = nums[i];
            int len = 1;
            while (seen.contains(target+1)) {
                len++;
                target++;
            }
            // store longest length so far
            res = max(res,len);
        }

        return res;

    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L= 0; int R = 0;
        while (R < nums.size()) {
            nums[L]= nums[R];
            while (R < nums.size() && nums[R] == nums[L]) R++;
            L++;
        }
        return L;
    }
};
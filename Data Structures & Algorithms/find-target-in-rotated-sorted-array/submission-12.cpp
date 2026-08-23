class Solution {
public:

    int oracle(vector<int>& nums, int L, int M, int R, int target) {
        // monotonic case, normal binary search
        if (nums[L] <= nums[R]) {
            if (nums[M] > target) return -1;
            if (nums[M] < target) return 1;

            //exit case
            return 0;
        }

        else {
            // need to go higher than target
            if (nums[M] < target) {
                // monotonic [M,R] case 
                if (nums[M] <= nums[R]) {
                    // if in range search right normally
                    if (nums[R] >= target) return 1;
                    return -1;
                }
                // otherwise max is between M and R
                return 1;
            }    
            if (nums[M] > target) {
                // monotonic [L,M] case
                if (nums[L] <= nums[M]) {
                    // if in range search left normally
                    if (nums[L] <= target) return -1;
                    return 1;
                }
                // otherwise minium is between L and M
                return -1;
            }
            // exit case
            return 0;
        }
    }
    int search(vector<int>& nums, int target) {
        int L = 0; int R = nums.size()-1;
        while (L <= R) {
            int M = L + (R-L)/2;
            int dir = oracle(nums,L,M,R,target);
            // cout << L << " " << M << " " << R << " " << dir << "\n";
            if (dir < 0) R = M-1;
            else if (dir > 0) L = M+1;
            else return M;
        }

        return -1;
    }
};

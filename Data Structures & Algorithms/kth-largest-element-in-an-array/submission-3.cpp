class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // constants
        int K = k;
        int N = nums.size();
        int target = N-k;
        // start + end indices
        int S = 0;
        int E = N-1;

        // naive pivot selection rightmost
        int pivot = E;

        while (true) {
            int L = S;
            int pNum = nums[pivot];
            for (int R = S; R < pivot; R++) {
                // scan for elements < pivot
                if (nums[R] < pNum) {
                    swap(nums[R],nums[L]);
                    L++;
                }
            }


            swap(nums[pivot],nums[L]);
            // search in the top K indicices
            if (L < target) {
                S = L+1;
                pivot = E;
            } else if (L > target) {
                E = L-1;
                pivot = E;
            } else {
                break;
            }
        }
        return nums[target];

    }
};

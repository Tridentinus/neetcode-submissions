class Solution {
public:

    // basic approach: oracle over range(0,n-1)
    int oracle(vector<int> &nums, int L, int M, int R) {
        // if (M<L || M > R) cout<< "oob M";
        // if (L < 0) cout << "oob L";
        // if (R == nums.size()) cout << "oob R";
        // cout << L << M << R;
        // return 0;
        // cout << nums[L] << " " << nums[M] << " " << nums[R]<< " ";
        if (nums[L] <= nums[R]) {
            // the minimum is actually at the left index
            return 0;
        }
        else {
            // if L->M monotonic search right
            if (nums[L] <= nums[M]) return 1;
            // if M->R is monotonic search left inclusive
            return -1;
        }

    }

    int findMin(vector<int> &nums) {
        int L = 0; int R = nums.size()-1;
        int M = 0;
        while (L <= R) {
            int M = L + (R-L)/2;
            int dir = oracle(nums,L,M,R);
            if (dir < 0) R = M;
            else if (dir > 0) L = M+1;
            else return nums[L];
        }    

        return nums[M];
        
    }
};

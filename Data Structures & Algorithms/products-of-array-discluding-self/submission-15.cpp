class Solution {

private:
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> out(N,1);

        int prodL =1;
        for (size_t i = 0; i < N; i++) {
            out[i] = prodL;
            prodL *= nums[i];
        }
        int prodR = 1;
        for (int i = N-1; i >= 0; --i) {
            out[i] *= prodR;
            prodR *= nums[i];
        }

        return out;

    }
};

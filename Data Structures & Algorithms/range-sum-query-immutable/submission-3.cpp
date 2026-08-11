class NumArray {

// cleaned up
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) : sums(nums.size()+1,0) {
        for (size_t i = 0; i < nums.size(); i++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }

    
    int sumRange(int left, int right) {
        return sums[right+1] - sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
class NumArray {

private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        sums.resize(nums.size()+1);
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sums[i+1] = sum;
            cout << sums[i] << endl;
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
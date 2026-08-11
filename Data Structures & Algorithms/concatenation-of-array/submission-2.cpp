class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N = nums.size();
        vector<int> res;
        res.resize(2*N);
        
        for (int i = 0; i < N; i++) {
            res[i] = res[i+N] = nums[i];
        }
        return res;
    }
};
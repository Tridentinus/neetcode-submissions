class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N = nums.size();
        vector<int> res = nums;
        res.insert(res.end(),nums.begin(),nums.end());
        return res;
    }
};
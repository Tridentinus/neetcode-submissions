class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& subseqs, int i, vector<int>& subseq ,int target) {
        // if we hit leaf before matching sum return
        if (i == nums.size()) return;

       

        // if we overshot target we need to backtrack
        if (target < 0) {
            return;
        }
         // if we hit target we are done since elements are positive
        if (target == 0) {
            subseqs.push_back(subseq);
            return;
        }
        // otherwise we try with and without current element

        subseq.push_back(nums[i]);
        dfs(nums,subseqs,i,subseq,target-nums[i]);
        subseq.pop_back();
        dfs(nums,subseqs,i+1,subseq,target);





    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> subseqs;
        vector<int> subseq;

        dfs(nums,subseqs,0,subseq,target);

        return subseqs;
    }
};

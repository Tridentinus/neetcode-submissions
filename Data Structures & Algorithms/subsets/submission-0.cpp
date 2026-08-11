class Solution {
public:

    void dfs(const vector<int>& nums,vector<vector<int>>& subsets, int i,vector<int>& subset) {
        // base case we have made a decision on every node so far
        // so we commit our subset to subsets
        if (i == nums.size()) 
        {
            subsets.push_back(subset);
            return;
        }
        // else we a make a forward call with an without the most recent element

        // with
        subset.push_back(nums[i]);
        dfs(nums,subsets,i+1,subset);
        // without
        subset.pop_back();
        dfs(nums,subsets,i+1,subset);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // all possible subsets of numbers

        // this is like going down a strictly binary decision tree of height (n) 

        vector<vector<int>> subsets;
        vector<int> subset; 

        dfs(nums,subsets,0,subset);

        return subsets;



        
    }
};

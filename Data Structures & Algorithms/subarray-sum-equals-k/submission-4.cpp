class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> premap;
        
        int sum = 0;
        premap[0] = 1;
        for (size_t i = 0; i < nums.size(); i++) {
            // prefix sum
            if (i>0) {
                nums[i] += nums[i-1];
            }

            // update sum (0 fills when not found)
            sum += premap[nums[i]-k];


            // update map
            premap[nums[i]]++;


        }

        return sum;





        
    }
};
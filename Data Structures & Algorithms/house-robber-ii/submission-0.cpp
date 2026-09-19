class Solution {
public:
    int house_robber_1(vector<int>& nums) {
        int N = nums.size();
        if (N ==1 ) return nums[0];
        if (N ==2 ) return max(nums[0],nums[1]);

        pair<int,int> dp; // T, NT

        dp.first = nums[1];
        dp.second = nums[0];

        for (int i =2; i < N; i++) {
            auto [T,NT] = dp;
            // Ti = NTi-1 + numsi
            dp.first = nums[i] + NT;
            // NTi = Ti-1
            dp.second = max(T,NT);
        }

        return max(dp.first,dp.second);


    }


    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N ==1 ) return nums[0];
        if (N ==2 ) return max(nums[0],nums[1]);
        
        // omit first element
        vector<int> nums1(nums.begin()+1,nums.end());
        // omit last element
        vector<int> nums2(nums.begin(),nums.end()-1);


        return max(house_robber_1(nums1),house_robber_1(nums2));


    }
};
     
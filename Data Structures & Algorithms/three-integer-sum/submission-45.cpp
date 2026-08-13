class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // sort all elements
        sort(nums.begin(), nums.end(), [](const auto a, const auto b){return a < b;});


        /*
        -4 -1 -1 0 1 2 
        
        -3 -2 -1 0 1 2 3


        */
        int L = 0, R = nums.size()-1;
        vector<vector<int>> res;

        // solve twoSum over multiple targets (t val)
        for (int t = 0; t < nums.size(); t++) {
            if (t >0  && nums[t] == nums[t-1]) continue;
            int target = -nums[t];
            cout << "target : " << target << endl;
            int L = t+1, R = nums.size()-1;
            while (L < R ) {
                if (nums[L] + nums[R] < target) {
                    L++;
                    continue;
                }

                if (nums[L] + nums[R] > target) {
                    R--;
                    continue;
                }

                // hit target
                res.push_back({nums[L],nums[R],nums[t]});

                // multiple solutions check
                L++;
                R--;
                while (L < R && nums[L] == nums[L - 1]) {
                    L++;
                }

            }
        }

        return res;
        

    }
};

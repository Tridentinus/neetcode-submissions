class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int N = nums.size();
        int K = k;
        vector<int> res;
        priority_queue<pair<int,int>> maxHeap;


        for (int i =0; i < K; i++) {
            maxHeap.push({nums[i],i});
        }

        res.push_back(maxHeap.top().first);

        for (int r = K; r < N; r++) {
            maxHeap.push({nums[r],r});
            // if evicting (a) window max
            while (maxHeap.top().second <= r-k) {
                maxHeap.pop();
            }
            res.push_back(maxHeap.top().first);
        }
        return res;
        
    }
};

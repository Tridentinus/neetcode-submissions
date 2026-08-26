class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kminHeap;

        for (const auto& num : nums) {
            if (kminHeap.size()< k || num > kminHeap.top()) {
                kminHeap.push(num); 
                if (kminHeap.size() > k) kminHeap.pop();
            }
        }

        return kminHeap.top();

    }
};

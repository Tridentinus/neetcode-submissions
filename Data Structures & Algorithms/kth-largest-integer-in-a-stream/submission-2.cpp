class KthLargest {
public:
    priority_queue<int,vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // T: O(nlogK)
        // S: O(K)
        this->k = k;
        for (auto n: nums) {
            minHeap.push(n);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
    }
    //T: O(logK)
    //S: O(1)
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

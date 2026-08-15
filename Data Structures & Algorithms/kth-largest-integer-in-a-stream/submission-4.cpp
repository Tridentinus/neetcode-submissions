class KthLargest {
private:

    priority_queue<int,vector<int>,greater<int>> minheap;
    int cap;
public:
    // O(nlogK + O(n))
    // S = O(n)
    KthLargest(int k, vector<int>& nums) : cap(k) {
        for (auto n : nums) {
            minheap.push(n);
        }

        while (minheap.size() > cap) {
            minheap.pop();
        }
        
    }
    // S: O(K)
    // O(logK)
    int add(int val) {

        minheap.push(val);

        while (minheap.size() > cap) {
            minheap.pop();
        }

        return minheap.top();
        
    }
};

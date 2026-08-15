class KthLargest {
private:

    priority_queue<int,vector<int>,greater<int>> minheap;
    int cap;
public:

    KthLargest(int k, vector<int>& nums) : cap(k) {
        for (auto n : nums) {
            minheap.push(n);
        }
        
    }
    // O(logN)
    int add(int val) {

        minheap.push(val);

        while (minheap.size() > cap) {
            minheap.pop();
        }

        return minheap.top();
        
    }
};

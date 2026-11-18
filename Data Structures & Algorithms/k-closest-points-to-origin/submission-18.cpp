class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // naive solve: single bounded heap
        priority_queue<vector<int>,vector<vector<int>>, less<vector<int>>> maxHeap;
        vector<vector<int>> out;
        for (auto p : points) {
            int x = p[0];
            int y = p[1];
            int dist = pow(x,2) + pow(y,2); 
            // partial filled heap
            if (maxHeap.size() < k) {
                maxHeap.push({dist,x,y});
            }
            // keep only top K
            else {
                if (dist < maxHeap.top()[0]) {
                    maxHeap.pop();
                    maxHeap.push({dist,x,y});
                }
            }
        }
        for (int i = 0; i < k; i++) {
            out.push_back({maxHeap.top()[1],maxHeap.top()[2]});
            maxHeap.pop();
        }
        return out;
        
    }
};

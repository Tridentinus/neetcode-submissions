class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,less<vector<int>>> maxHeap;

        for (const auto& p :points) {
            int x = p[0];
            int y = p[1];
            int dist = pow(x,2) + pow(y,2);
            if (maxHeap.size() < k) {
                // cout << "adding " << x << " " << y << " : " << dist << "\n";
                maxHeap.push({dist,x,y});
        
            } else {
                if (maxHeap.top()[0] > dist) {
                    maxHeap.push({dist,x,y});
                    maxHeap.pop();
                }
            }
        }
        vector<vector<int>> res;
        res.reserve(k);
        for (int i = 0; i < k; i++) {
            auto entry = maxHeap.top();
            res.push_back({entry[1],entry[2]});
            maxHeap.pop();
        }


        return res;
        

        
    }
};

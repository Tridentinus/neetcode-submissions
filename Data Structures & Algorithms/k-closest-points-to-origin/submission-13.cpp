class Solution {
public:

    int dist(const vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // quick select with naive pivot selection
        int S = 0;
        int E = points.size()-1;
        int K = k;
        vector<vector<int>> res;
        res.reserve(k);
        int pivot = E;
        while (true) {
            int L = S;
            int pDist = dist(points[pivot]);
            for (int R = S; R < pivot; R++) {
                if (dist(points[R]) < pDist) {
                    // use swap to avoid deep copy
                    swap(points[R],points[L]);
                    L++;
                } 
            }
            // use swap to avoid deep copy
            swap(points[pivot],points[L]);
            if (L < k-1)  {
                S = L+1;
                pivot = E;
            }
            else if (L > k-1) {
                pivot = L-1;
                E = pivot;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < K; i++) {
            res.push_back(points[i]);
        }
        return res;
       
    }
};

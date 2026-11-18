class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };
        nth_element(points.begin(), points.begin() + k, points.end(),comp);

        return vector<vector<int>>(points.begin(), points.begin()+k);    }
};

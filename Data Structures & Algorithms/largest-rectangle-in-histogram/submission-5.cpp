class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {

        // entry: idx of entry
        stack<int> stk;
        int N = heights.size();
        int res = 0;
        for (int i = 0; i <= N ; i ++) {
            while (!stk.empty() && ( i == N|| heights[i] <= heights[stk.top()])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() -1;
                res = max(res,h*w);
            }
            stk.push(i);
        }
        return res;
    }
};

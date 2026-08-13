class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<pair<int,int>> stk;

        for (int i =0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stk.empty() && stk.top().first < t) {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({t,i});
        }

        return res;
    }
};

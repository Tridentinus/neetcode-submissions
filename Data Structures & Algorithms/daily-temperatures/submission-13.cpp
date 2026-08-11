class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        stack<pair<int,int>> stck;
        vector<int> results(N,0);
        for (int i = 0; i < N; i++) {
            while (!stck.empty() && stck.top().first < temperatures[i]) {
                results[stck.top().second] = i - stck.top().second;
                stck.pop();
            }

            stck.push({temperatures[i],i});
        }


        return results;


    }
};

class Solution {
public:

    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<int,int>> stk;

        vector<pair<int,int>> cars;

        int N= speed.size();
        cars.reserve(N);

        for (int i = 0; i < N; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // sort (NlogN)
        sort(cars.begin(), cars.end(), [](const auto A, const auto B) {return A > B;});
        
        for (auto c: cars) {
            if (stk.empty()) {stk.push(c); continue;}
            auto obs = stk.top();

            // if can catch up in time for front car to reach then its the bottleneck for next dude
            if ((c.second - obs.second)*(target - obs.first)/(obs.second) >= (obs.first-c.first)) {
                // cout << c.first << " " << c.second << " consumed by " << obs.first << " " << obs.second << endl; 
                continue;
            }



            // otherwise i am the the new obstacle

            // cout << "push"  << c.first << " " << c.second << endl;
            stk.push(c);
        }

        return stk.size();

        
    }
};

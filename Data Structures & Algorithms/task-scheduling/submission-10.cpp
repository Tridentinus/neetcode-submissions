class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> freqQ;
        queue<pair<int,int>> cooldown;

        for (const auto& t : tasks) {
            counts[t-'A']++;
        }

        for (int t = 0; t < 26; t++) {
            if (counts[t]) freqQ.push({counts[t],t});
        }

   


        int T = 0;
        while (true) {
            if (cooldown.front().first == T) {
                auto [_, task] = cooldown.front();
                cooldown.pop();
                freqQ.push({counts[task],task});
                // cout << (char) (task+'A') << " off Q \n"; 
                continue;
            } 
            if (freqQ.size() > 0) {
                auto [cnt, task] = freqQ.top();
                freqQ.pop();
                // cout << T<< ":" <<(char) (task+'A') << "\n"; 
                if (--counts[task]) {
                    cooldown.push({T+n+1,task});
                    // cout << " cooling " << (char) (task+'A') << " until " << T+n+1 << "\n";
                }
                T++;
            } else if (cooldown.size() > 0) {
                // cout << "idle\n";
                T++;
            } else {
                break;
            }
            // if (startQ.top().first > T) {
            //     T++;    
            //     continue;
            // }
            // auto [start, task] = startQ.top();
            // startQ.pop();
            // if (counts[task]==0) continue;
            // counts[task]--;
            // T++;
            // if (counts[task] > 0)  {
            //     startQ.push({T+n,task});
            // }
        }

        return T;



    }
};

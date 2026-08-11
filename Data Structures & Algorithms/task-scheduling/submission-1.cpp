class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        

        vector<int> counts(26,0);
        for (char t: tasks) {
            counts[int(t-'A')]++;
        }

        priority_queue<int> maxHeap;
        for (int cnt: counts) {
            if (cnt) maxHeap.push(cnt);
        }



        int cycles = 0;
        queue<pair<int,int>> q;
        while(!maxHeap.empty() || !q.empty()) {
            cycles++;

            if (maxHeap.empty()) { // no more pending tasks
                cycles = q.front().second; // wait until next valid time
            } else {
                int cnt = maxHeap.top() -1; // decrement the most frequent pending taks
                maxHeap.pop();

                // if more of it remains we add it to queue for next valid time
                if (cnt) q.push({cnt,cycles+n});
            }

            // if our next queued task has become ready add to queue
            if (!q.empty() && q.front().second == cycles) {
                maxHeap.push(q.front().first);
                q.pop();
            }



        }

        return cycles;


    }
};

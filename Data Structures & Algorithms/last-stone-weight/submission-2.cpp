class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (auto stone: stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size()) {
            if (maxHeap.size() == 1) {
                return maxHeap.top();
            }

            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            if (stone1 == stone2) continue;
            maxHeap.push(abs(stone1-stone2));
        }

        return 0;
    }
};

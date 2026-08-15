class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        priority_queue<int,vector<int>,less<int>> maxHeap;


        for (auto stone: stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            auto stone1 = maxHeap.top();
            maxHeap.pop();

            auto stone2 = maxHeap.top();
            maxHeap.pop();

            if (stone1 == stone2) continue;
            else maxHeap.push(abs(stone1-stone2));
        }
        if (maxHeap.size() == 0) return 0;

        return maxHeap.top();
        
    }
};

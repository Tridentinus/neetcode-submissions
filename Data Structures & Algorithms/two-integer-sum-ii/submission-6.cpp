class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0; int R = numbers.size()-1;

        while (L < R) {
            if (numbers[L] + numbers[R] < target) {
                L++;
                continue;
            }
            if (numbers[L] + numbers[R] > target) {
                R--;
                continue;
            }

            return {L+1, R+1};
        }
        
    }
};

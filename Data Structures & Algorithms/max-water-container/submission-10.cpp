class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
        plan: two pointers 
        L and R not fast slow because distance dimension strictly dominates 

        area = min(heights) * distance
        */
        

        int L = 0, R = heights.size()-1;
        int area = (R - L) * min(heights[L],heights[R]);
        while (L < R) {
            if (heights[L] < heights[R]) {
                L++;
            }
            else {
                R--;
            }

            // check if new area is larger?
            area = max(area, (R - L) * min(heights[L],heights[R]));
        }

        return area;
    }
};

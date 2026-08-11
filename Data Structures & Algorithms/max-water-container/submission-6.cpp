class Solution {
public:
    int maxArea(vector<int>& heights) {

        int N = heights.size();
        int L = 0;
        int R = N-1;

        //initial best

        int maxArea = (R-L) * min(heights[L], heights[R]);
        cout << "maxArea: " << maxArea << endl;
        // can we do better
        while (L < R) {
            // if limiting factor is L
            if (heights[L] < heights[R]) {
                cout << "advance left" << endl;
                L++;
                maxArea = max((R-L) * min(heights[L], heights[R]),maxArea);
            
            } else {
                cout << "advance right" << endl;
                R--;
                maxArea = max((R-L) * min(heights[L], heights[R]),maxArea);
            }
            cout << "maxArea: " << maxArea << endl;

        }

        return maxArea;





        



    }
};

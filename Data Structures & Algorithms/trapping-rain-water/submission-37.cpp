class Solution {
public:
    int trap(vector<int>& height) {
        /*
        Automatically feeling fast and slow pointers to cover every gap and conditionally add a running sum
        ahh but that fails the 4 2 3 case since it is same as 3 2 3

        new ideas L and R pointers
        we are constrained by the shorter of the two


        2 0 3 1 0 1 3
        */
        int L = 0, R = height.size()-1;
        int res = 0;
        int maxL = height[L], maxR = height[R];
        while (L < R) {
            if (maxL < maxR) {
                L++;
                maxL = max(maxL,height[L]);
                res+= maxL - height[L];
            }
            else {
                R--;
                maxR = max(maxR, height[R]);
                res+= maxR - height[R];
            }
        }
        return res;
        
    }
};

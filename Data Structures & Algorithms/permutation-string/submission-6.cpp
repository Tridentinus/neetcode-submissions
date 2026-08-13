class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int N1 = s1.size();
        array<int,26> target; 
        array<int,26> window;
        

        // build window/target arrays
        for (int R = 0; R < N1; R++) {
            int c1 = s1[R]-'a';
            int c2 = s2[R]-'a';
            target[c1]++;
            window[c2]++;
        }
        if (window == target) return true;

        int L = 0;

        for (int R = N1; R < s2.size(); R++) {
            // evict left
            int cL = s2[L]-'a';
            window[cL]--;
            L++;
            // add right
            int cR = s2[R]-'a';
            window[cR]++;
            // check if valid
            if (window == target) return true;
        }
        return false;
        
    }
};

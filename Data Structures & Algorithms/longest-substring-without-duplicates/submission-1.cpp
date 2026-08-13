class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> window;
        int res = 0;
        int N = s.size();

        int L = 0, R = 0;
        while (R < N) {
            while (window[s[R]]) {
                window[s[L]]--;
                L++;
            }
            window[s[R]]++;
            res = max(res,R-L+1);
            R++;
        }

        return res;
    }
};

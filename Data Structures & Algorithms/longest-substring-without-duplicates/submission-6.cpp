class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastseen(256,-1);
        int res = 0;
        int N = s.size();

        int L = 0;

        for (int R = 0; R < N; R++) {
            if (lastseen[s[R]] >= L) {
                L=lastseen[s[R]]+1;
            }

            lastseen[s[R]] = R;
            res = max(res,R-L+1);
        }
        return res;
    }
};

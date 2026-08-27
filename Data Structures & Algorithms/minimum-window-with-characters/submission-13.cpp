class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> counts(128,0);
        for (auto c: t) {
            counts[c]++;
        }
        // output holder/checking
        int required = t.size();
        int start = 0;
        int min = INT_MAX;

        string res = "";

        
        int sLen = s.size();
        int tLen = t.size();
        // start search on first valid char
        int L = 0;
        for (int R = L; R < s.size(); R++) {
            if (counts[s[R]] > 0) {
                required--;
            }

            counts[s[R]]--;

            while (required ==0) {
                if (R-L+1 < min) {
                    min = R-L+1;
                    start = L;
                }

                if (++counts[s[L]]>0) required++;
                L++;
            }
        }

        return min == INT_MAX ? "" : s.substr(start, min);
    }
};

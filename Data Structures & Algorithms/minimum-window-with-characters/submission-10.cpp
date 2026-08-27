class Solution {
public:
    string minWindow(string s, string t) {
        // set of all unique t chars
        unordered_set<char> tset;
        // dictionary of t counts
        unordered_map<char,int> tmap;
        for (auto c: t) {
            tset.insert(c);
            tmap[c]++;
        }

        // output holder/checking
        int unique = tset.size();
        int valid = 0;
        int min = numeric_limits<int>::max();
        string res = "";
        // dictionary of window counts
        unordered_map<char,int> window;

        
        int sLen = s.size();
        int tLen = t.size();
        // start search on first valid char
        int L = 0;
        while (L < sLen && !tset.contains(s[L])) {
            L++;
        }
        for (int R = L; R < sLen; R++) {
            auto c = s[R];
            if (tset.contains(c)) {
                // increment window count and check if new valid entry
                if (++window[c] == tmap[c]) valid++;
                // if there is a surplus move L to eliminate preserving valid
                while (L < R) {
                    if (!tset.contains(s[L]) ) {
                        L++;
                    } else if (window[s[L]] > tmap[s[L]]) {
                        window[s[L]]--;
                        L++;
                    } else {
                        break;
                    }
                }
                // check if valid
                if (valid == unique && (R - L + 1 < min)) {
                    res = s.substr(L,R-L+1);
                    min = R - L + 1;
                    cout << res << "\n";
                }
            }
        }

        return res;
    }
};

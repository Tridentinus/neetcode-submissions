class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freqs;
        unordered_map<char,int> window;


        for (auto c: t) {
            freqs[c]++;
        }
        int M = freqs.size();
        

        int L = 0;
        int optL = -1;
        int optR = -1;
        int minLen = INT_MAX;

        int matches = 0;
        int N = s.size();
        for (int R = 0; R < N; R++) {
            // add new char
            char c = s[R];
            window[c]++;

            if (freqs[c] && window[c] == freqs[c]) matches++;

            // prune from left while valid
            while (matches == M) {
                if ((R-L+1) < minLen) {
                    optL = L;
                    optR = R;
                    minLen = R-L+1;
                }

                // account for left prune case
                c = s[L];
                window[c]--;
                if (freqs[c] && window[c] < freqs[c]) matches--;
                L++;
            }
        }


        return minLen == INT_MAX ? "" : s.substr(optL, minLen);

        
    }
};

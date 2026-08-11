class Solution {
public:
    string minWindow(string s, string t) {
        // we need ref frequencies of the t chars
        unordered_map<char,int> freqs;
        unordered_map<char,int> window;
        
        int N = s.size();
        
        // T: O(len(t)) S: O(52)
        for (auto c : t) {
            freqs[c]++;
        }
        int M = freqs.size();
        int matches = 0;
        int l = 0; 
        int len = INT_MAX;
        int l_prime = -1; int r_prime = -1;
        // for free qe can skip the first few entries if they dont match any of the string
        // while (l < N && !freqs[s[l]]) l++;

        for (int r = 0; r < N; r++) {
            // as we expand rightwards we adjust window count
            char c = s[r];
            window[c]++;

            // if this is a match add to matches
            if (freqs[c] && window[c] == freqs[c]) matches++;

            // if we have everything prune from the left 
            while (matches == M) {
                // preserve best result
                if ( (r - l +1 ) < len) {
                    len = r - l +1;
                    l_prime =l;
                    r_prime =r;
                }

                // account for pruning eviction
                c = s[l];
                window[c]--;
                if (freqs[c] && window[c] < freqs[c]) matches--;

                // advance left edge
                l++;
            }                
        }
        // return "";
        return len == INT_MAX ? "" : s.substr(l_prime,len);


    }
};

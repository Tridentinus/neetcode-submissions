class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);

        // fill s1Count to compare against O(n1) time
        // also fill first n1 sized window of s2 for checks
        for (int i = 0; i < s1.length(); i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        // perform fist mathcing in constant ti me
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            // if already fully matched we done
            if (matches == 26) {
                return true;
            }

            int index = s2[r] - 'a';
            // account for newest added entry in window counts
            s2Count[index]++;
            // if this change gets us to right count for added char +1 match
            if (s1Count[index] == s2Count[index]) {
                matches++;
            }
            // if this change doesnt *AND REMOVED* a previous match -1 match  
            else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            //account for evicted entry in window counts 
            index = s2[l] - 'a';
            s2Count[index]--;

            // if this eviction led us to match +1 match
            if (s1Count[index] == s2Count[index]) {
                matches++;
            }
            // if didnt *AND REMOVED* a match -1 match 
            else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
            // advance the left border to protect loop invariant of window size
            l++;
        }
        return matches == 26;
    }
};
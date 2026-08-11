class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> scounts;
        unordered_map<char, int> tcounts;

        for (int i = 0; i < s.size();i++) {
            scounts[s[i]]++;
            tcounts[t[i]]++;
        }

        for (const auto& [letter,count]: scounts) {
            if (tcounts[letter] != count) return false;
        }

        return true;
    }
};

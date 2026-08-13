class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string> > strMap;
        vector<vector<string>> res;
        for (const auto& str: strs) { 
            vector<int> count(26,0);
            // form the hashable char count array
            for (const auto& c : str) {
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for (size_t i =1; i < 26; i++) {
                key+= ',' + to_string(count[i]);
            }
            strMap[key].push_back(str);
        }

        for (const auto& [k,v]: strMap) {
            res.push_back(v);
        }

        return res;

    }
};

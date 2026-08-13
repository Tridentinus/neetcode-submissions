class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string, vector<string> > strMap;
        for (const auto& str: strs) { 
            string key(26,0);
            // form the hashable key in place no secondary storage
            for (const auto& c : str) {
                key[c-'a']++;
            }
            strMap[key].push_back(str);
        }
        
        vector<vector<string>> res;
        res.reserve(strMap.size());
        for (auto& [k,v]: strMap) {
            res.push_back(move(v));
        }

        return res;

    }
};

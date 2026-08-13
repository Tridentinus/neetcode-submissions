class Solution {
    vector<int> seps;
public:

    string encode(vector<string>& strs) {
        string code;
        for (const auto& s : strs) {
            code+= to_string(s.size());
            code+= "#";
            code+= s;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int l = 0;
        while (l < s.size()) {
            int r = l;
            while (s[r] != '#') {
                r++;
            }
            int len = stoi(s.substr(l,r-l+1));
            res.push_back(s.substr(r+1, len));
            l = r+len+1;
        }
        return res;
    }
};

class Solution {
    vector<int> seps;
public:

    string encode(vector<string>& strs) {
        string code;
        for (const auto& s : strs) {
            code+= s;
            seps.push_back(s.size());
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> res;
        res.reserve(seps.size());
        int i = 0;
        for (auto sep: seps) {
            res.push_back(s.substr(i,sep));
            i+= sep;
        }
        return res;
    }
};

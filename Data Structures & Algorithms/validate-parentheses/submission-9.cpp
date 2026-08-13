class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        unordered_set<char> B({'(','[','{'});
        unordered_set<char> E({')',']','}'});
        unordered_map<char,char> hashMap = {{')','('},{']','['},{'}','{'}};
        for (auto c: s) {
            if (B.contains(c)) {
                Stack.push(c);
            }
            else if (E.contains(c)) {
                if (Stack.empty()) return false;
                if (hashMap[c] != Stack.top()) return false; 
                Stack.pop();
            }
        }
        return Stack.empty();

    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;

        for (auto s: tokens) {
            if (!isOp(s)) {
                stk.push(s);
            }
            else {
                int R = stoi(stk.top()); stk.pop();
                int L = stoi(stk.top()); stk.pop();

                if (s == "+") stk.push(to_string(L + R));
                if (s == "-") stk.push(to_string(L - R));
                if (s == "*") stk.push(to_string(L * R));
                if (s == "/") stk.push(to_string(L / R));
       
            }
        }

        return stoi(stk.top());
    }

    bool isOp (const string& token) {
        return (token == "+" || token == "*" || token == "-" || token == "/");
    }
};

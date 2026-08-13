class MinStack {

// Pair : {value, oldMin}
vector<pair<int,int>> S;

public:
    MinStack()  {
    }
    
    void push(int val) {
       if (S.empty()) S.push_back({val,val});
       else S.push_back({val,min(val,S.back().second)});
    }
    
    void pop() {
        S.pop_back();
    }
    
    int top() {
        return S.back().first;
    }
    
    int getMin() {
        return S.back().second;
    }
};

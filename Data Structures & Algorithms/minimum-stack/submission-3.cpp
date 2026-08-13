class MinStack {

// Pair : {value, oldMin}
vector<pair<int,int>> S;
int currMin;

public:
    MinStack() : currMin(numeric_limits<int>::max()) {
    }
    
    void push(int val) {
       S.push_back({val,currMin});
       currMin = min(currMin, val);
    }
    
    void pop() {
        currMin = S.back().second;
        S.pop_back();
    }
    
    int top() {
        return S.back().first;
    }
    
    int getMin() {
        return currMin;
    }
};

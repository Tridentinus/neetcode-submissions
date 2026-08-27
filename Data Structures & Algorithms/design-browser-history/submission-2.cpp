class BrowserHistory {
public:
    vector<string> history;
    size_t curr;
    size_t maxHist;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
        maxHist = 0;
    }
    
    void visit(string url) {

        if (curr == maxHist) {
            history.push_back(url);
        } else {
            history[curr+1] = url;
        }
        curr++;
        maxHist = curr;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr != 0) curr--;
            else break;
        }
        return history[curr];
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr < maxHist) curr++;
            else break;
        }
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
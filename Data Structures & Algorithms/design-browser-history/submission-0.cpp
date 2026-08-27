class BrowserHistory {
public:
    struct Node {
        string url;
        Node* prev;
        Node* next;
    };
    

    Node * curr;


    BrowserHistory(string homepage) {

        curr = new Node{homepage,nullptr,nullptr};
    }
    
    void visit(string url) {
        curr->next = new Node{url,curr,nullptr};
        curr = curr->next;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->prev != nullptr) curr = curr->prev;
            else break;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->next) curr = curr->next;
            else break;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
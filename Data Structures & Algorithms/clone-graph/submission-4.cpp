/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node * dfs(Node * src, unordered_map<Node*,Node*>& cloneMap) {
        if (src == nullptr) return nullptr;
        // visited
        if (cloneMap.contains(src)) return cloneMap[src];

        Node * clone = new Node( src->val);
        cloneMap[src] = clone;
        for (Node * n : src->neighbors) {
            clone->neighbors.push_back(dfs(n,cloneMap));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {

        if (node == nullptr) return nullptr;

        unordered_map<Node*,Node*> cloneMap;

        queue<Node*> Q;
        Q.push(node);
        cloneMap[node] = new Node(node->val);

        while (!Q.empty()) {
            Node* curr = Q.front();
            Q.pop();
            if (curr == nullptr) continue;
            for (auto n : curr->neighbors) {
                if (!cloneMap.contains(n)){
                    cloneMap[n] = new Node(n->val);
                    Q.push(n);
                }
                cloneMap[curr]->neighbors.push_back(cloneMap[n]);
            }
        }
        

        return cloneMap[node];
        
    }
};

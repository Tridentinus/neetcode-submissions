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

        unordered_map<Node*,Node*> cloneMap;

        return dfs(node, cloneMap);
        
    }
};

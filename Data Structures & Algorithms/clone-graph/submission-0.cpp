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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> oldToNew;

        queue<Node*> Q;
        oldToNew[node] = new Node(node->val);
        Q.push(node);


        while (Q.size()) {
            Node * cur = Q.front();
            Q.pop();

            for (Node* n : cur->neighbors) {
                if (!oldToNew.contains(n)) {
                    oldToNew[n] = new Node(n->val);
                    Q.push(n);
                }

                oldToNew[cur]->neighbors.push_back(oldToNew[n]);
            }
        }

        return oldToNew[node];


    }
};

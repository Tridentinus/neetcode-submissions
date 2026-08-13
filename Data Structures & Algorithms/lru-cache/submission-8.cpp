class LRUCache {

private:
    struct Node {
        int key;
        int value;
        Node * prev;
        Node * next;
    };

    void remove(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node * head,Node* node) {
        node->prev =head;
        node->next =head->next;
        head->next->prev = node;
        head->next = node;
    }

    int cap;
    Node * LRU;
    Node * MRU;
    Node * head;
    Node * tail;
    unordered_map<int,Node*> nodeMap;
public:

    
    LRUCache(int capacity) : cap(capacity), LRU(nullptr), MRU(nullptr){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (nodeMap.contains(key)) {
            Node * node = nodeMap[key];
            remove(node);
            insert(head,node);
            return node->value;
        }
        return -1;

    }
    
    void put(int key, int value) {
        // check if already in the cache
        if (nodeMap.contains(key)) {
            Node * node = nodeMap[key];
            remove(node);
            node->value = value;
            insert(head,node);
            return;
        }

        if (nodeMap.size() == cap) {
            Node * lru = tail->prev;
            remove(lru);
            nodeMap.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key,value,nullptr,nullptr);
        insert(head,node);
        nodeMap[key] = node;

    }
};

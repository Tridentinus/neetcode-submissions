class LRUCache {
public:

    // K : (value, order pointer)
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    int cap;
    // where value is the key
    list<int> order;
    LRUCache(int capacity) : cap(capacity) {
        cache.rehash(capacity);
    }
    
    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end()) return -1;
        
        // move node to back (MRU). done with a pointer swap (no heap alloc/dealloc)
        order.splice(order.end(),order,it->second.second);

        return it->second.first;
        
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        // if found
        if (it != cache.end()){
            order.splice(order.end(),order,it->second.second);
            it->second.first = value;
            return;
        }
        // if not found
        order.emplace_back(key);
        cache.insert({key,{value,prev(order.end())}});

        if (order.size() > cap) {
            cache.erase(order.front());
            order.pop_front();
        }

    }
};

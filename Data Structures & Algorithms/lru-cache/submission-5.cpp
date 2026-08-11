class LRUCache {
public:

    // K : (value, order pointer)
    unordered_map<int,pair<int,list<int>::iterator>> cache;
    int cap;
    // where value is the key
    list<int> order;
    LRUCache(int capacity) : cap(capacity) {
    }
    
    int get(int key) {
        auto it = cache.find(key);

        // if not contained return -1
        if (it == cache.end()) return -1;
        
        // if contained update the order and return
        auto o_it = it->second.second;
        // remove O(1)
        order.erase(o_it);
        // reinsert at tail
        order.emplace_back(it->first);
        // update KV iter
        cache[key].second = std::prev(order.end());

        return cache[key].first;
        
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        // if found
        if (it != cache.end()){
            auto o_it = it->second.second;
            order.erase(o_it);
            order.emplace_back(it->first);
            cache[key].second = prev(order.end());
            cache[key].first = value;
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

class LRUCache {
public:

    using List = list<pair<int,int>>;
    using ListIter = List::iterator;
    size_t K;
    List Q;
    unordered_map<int,ListIter> iterMap;
    LRUCache(int capacity) : K(capacity) {

    }
    
    int get(int key) {

        if (!iterMap.contains(key)) return -1;

        // get iter and make MRU
        ListIter iter = iterMap[key];
        Q.splice(Q.begin(),Q,iter);
        auto& [k,v]= *iter;

        return v;


        
    }
    
    void put(int key, int value) {
        if (iterMap.contains(key)) {
            ListIter iter = iterMap[key];
            Q.splice(Q.begin(),Q,iter);
            auto& [k,v]= *iter;
            v = value;
        }
        else {
            Q.push_front({key,value});
            iterMap[key] = Q.begin();
            if (Q.size() > K) {
                iterMap.erase(Q.back().first);
                Q.pop_back();
            }
        }
    }
};

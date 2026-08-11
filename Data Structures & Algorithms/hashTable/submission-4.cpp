class HashTable {
// Seperate chaining with LL
private:
    int cap_;
    int size_;
    vector<list<pair<int,int>>> map_;
public:
    HashTable(int capacity) : cap_(capacity), size_(0) {
        map_.resize(cap_);
    }

    void insert(int key, int value) {
        // idx = key % cap;
        int idx = key % cap_;

        // if the chain at idx isnt empty
        if (map_[idx].size()) {
            // iterate over the link until find key
            for (auto& p: map_[idx]) {
                // find match update and done
                if (p.first == key) {
                    p.second = value;
                    return;
                }
            }
        }

        // if chain empty or doesnt contain the key
        map_[idx].emplace_back(key,value);
        size_++;
        // check if need to resize
        if (2*size_ >= cap_) (*this).resize();
    }

    int get(int key) {
        int idx = key % cap_;

        if (map_[idx].size()) {
            // iterate over the link until find key
            for (auto& p: map_[idx]) {
                // find match return
                if (p.first == key) {
                    return p.second;
                }
            }
        } 

        // else not found
        return -1;

    }

    bool remove(int key) {
        int idx = key % cap_;

        if (map_[idx].size()) {
            // iterate over the link until find key
            for (auto it = map_[idx].begin(); it != map_[idx].end(); ++it) {
                if (it->first == key) {
                    map_[idx].erase(it); 
                    size_--;
                    return true;
                }
            }
        } 

        return false;
    }

    int getSize() const {
        return size_;
    }

    int getCapacity() const {
        return cap_;
    }

    void resize() {

        int oldcap_ = cap_;
        cap_ *=2;
        // move transfers ownership to oldMap of memeory without deep copy
        vector<list<pair<int, int>>> oldmap_ = std::move(map_);
        // fill in the hollowed map_ with enough copies
        map_.assign(cap_, list<pair<int, int>>());
        size_ = 0;
        for (auto p: oldmap_) {
            for (auto [key,value]: p) {
                insert(key,value);
            }
        }
        
    }
};

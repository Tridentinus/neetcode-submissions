class HashTable {
public:

    int cap_;
    int size_;
    vector<vector<pair<int,int>>> map_;

    HashTable(int capacity) : cap_(capacity), size_(0), map_(capacity) {
    }

    int hash (int key) {
        return key % cap_;
    }
    void insert(int key, int value) {
        int idx = hash(key);
        
        // if exists update
        for (auto & [k,v] : map_[idx]) {
            if (k == key) {
                v = value;
                return;
            }
        }

        map_[idx].push_back({key,value});

        size_++;

        if (size_ >= cap_/2.0) {
            resize();
        }
    }

    int get(int key) {
        int idx = hash(key);
        
        
        for (auto & [k,v] : map_[idx]) {
            if (k == key) {
                return v;
            }
        }

        return -1;
    }

    bool remove(int key) {
        int idx = hash(key);

        for (int i = 0; i < map_[idx].size(); i++) {
            if (map_[idx][i].first == key) {
                map_[idx].erase(map_[idx].begin() + i);
                size_--;
                return true;
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
        int oldCap = cap_;
        cap_ *= 2;

        vector<vector<pair<int, int>>> oldMap = map_;
        map_ = vector<vector<pair<int, int>>>(cap_);
        size_ = 0;

        for (int i = 0; i < oldCap; i++) {
            for (auto& [k, v] : oldMap[i]) {
                insert(k, v);
            }
        }
    }
};

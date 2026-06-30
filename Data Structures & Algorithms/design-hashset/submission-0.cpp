class MyHashSet {
    int numBuckets;
    std::vector<std::list<int>> buckets;

    int Hash(int key)
    {
        return key % numBuckets;
    }
public:
    MyHashSet() {
        numBuckets = 769;
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index = Hash(key);

        if (!contains(key)) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = Hash(key);
        auto& bucket = buckets[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }
    
    bool contains(int key) {
        int index = Hash(key);
        
        auto& bucket = buckets[index];

        return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
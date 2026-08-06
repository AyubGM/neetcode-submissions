class MyHashSet {

    static constexpr int size = 10007; 
    std::array<std::list<int>, size> map;
    
public:
    int Hash(int val) {
        return val % size;
    }
    
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = Hash(key); 
        if (!contains(key)) {
            map[index].push_back(key); 
        }
    }
    
    void remove(int key) {
        int index = Hash(key); 
        auto& bucket = map[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);
        if (it != bucket.end()) {
            bucket.erase(it);
        }
    }
    
    bool contains(int key) {
        int index = Hash(key);
        auto& bucket = map[index]; 
        
        return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};
class MyHashMap {
    static constexpr int m_Size = 10007;
    std::array<std::list<std::pair<int,int>>, m_Size> m_Buckets;
public:
    MyHashMap() {
        
    }
    int Hash(int key)
    {
        return key % m_Size;
    }
    
    void put(int key, int value) {
        int index = Hash(key);
        auto& bucket = m_Buckets[index];
        auto it = std::find_if(bucket.begin(), bucket.end(), 
            [key](const auto& p) { return p.first == key; });
        if (it != bucket.end())
        {
            it->second = value;
        } else
        {
            m_Buckets[index].push_back({key, value});
        }


    }
    
    int get(int key) {
        int index = Hash(key);
        auto& bucket = m_Buckets[index];
        auto it = std::find_if(bucket.begin(), bucket.end(), 
            [key](const auto& p) { return p.first == key; });
        if (it != bucket.end())
        {
           return it->second;
        } 
        return -1;
    }
    
    void remove(int key) {
         int index = Hash(key);
        auto& bucket = m_Buckets[index];
        auto it = std::find_if(bucket.begin(), bucket.end(), 
            [key](const auto& p) { return p.first == key; });
        if (it != bucket.end())
        {
           bucket.erase(it);
        } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
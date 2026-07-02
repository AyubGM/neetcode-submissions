class MyHashMap {
    int m_NumBuckets = 769;
    std::vector<std::list<std::pair<int, int>>> m_Buckets;

    int Hash(int key)
    {
        return key % m_NumBuckets;
    }
public:
    MyHashMap() {
       m_Buckets.resize(m_NumBuckets);
    }
    
    void put(int key, int value) {
        int index = Hash(key);
        for (auto& pair : m_Buckets[index])
        {
            if (pair.first == key) 
            {
                pair.second = value;
                return;
            }
        }
        m_Buckets[index].push_back({key, value});
    }
    
    int get(int key) {
         int index = Hash(key);
         for (const auto& pair : m_Buckets[index])
         {
            if (pair.first == key) 
            {
                return pair.second;
            }
         }
         return -1;
    }
    
    void remove(int key) {
        int index = Hash(key);
        auto& bucket = m_Buckets[index];
         for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                return;
            }
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
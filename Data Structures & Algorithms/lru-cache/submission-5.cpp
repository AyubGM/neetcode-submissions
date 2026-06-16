class LRUCache {
   private:
    int m_Capacity;
    std::list<std::pair<int, int>> m_CacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_Map;

   public:
    LRUCache(int capacity) : m_Capacity(capacity) {}

    int get(int key) {
        if (!m_Map.contains(key)) {
           return -1;
        }
        
        m_CacheList.splice(m_CacheList.end(), m_CacheList, m_Map[key]);

        return m_Map[key]->second;
    }

    void put(int key, int value) {
        if (m_Map.contains(key)) {
            m_Map[key]->second = value;
            m_CacheList.splice(m_CacheList.end(), m_CacheList, m_Map[key]);
            return;
        }
        if (m_Map.size() >= m_Capacity) {
            auto [k, v] = m_CacheList.front();
            m_CacheList.pop_front();
            m_Map.erase(k);
        }
        m_CacheList.push_back({key, value});
        m_Map[key] = --m_CacheList.end(); // Pointer arthimatics 
    }
};

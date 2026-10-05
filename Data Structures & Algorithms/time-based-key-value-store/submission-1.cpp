class TimeMap {
   private:
   std::unordered_map<std::string, std::vector<std::pair<int, string>>> m_Map;
   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m_Map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m_Map.find(key);
        if (it == m_Map.end()) {
            return "";
        }

        const auto& vec = it->second;

        auto upperBoundIt = std::upper_bound(
            vec.begin(), vec.end(), timestamp,
            [](int target_time, const std::pair<int, std::string>& item) {
                return target_time < item.first;
            }
        );

        if (upperBoundIt == vec.begin()) {
            return "";
        }

        return std::prev(upperBoundIt)->second;
    }
};

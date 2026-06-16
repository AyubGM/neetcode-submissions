class TimeMap {
   private:
    std::unordered_map < string, std::vector<std::pair<int, std::string>>> m_Map;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { m_Map[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (!m_Map.contains(key)) {
            return "";
        }

        string res = "";
        const auto& vec = m_Map[key];
        int left = 0;
        int right = vec.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if(vec[mid].first == timestamp)
            {
                return vec[mid].second;
            }

            if(vec[mid].first < timestamp )
            {
                res = vec[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return res;
    }
};

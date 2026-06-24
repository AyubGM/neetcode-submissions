struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return (hash<int>()(p.first) ^ (hash<int>()(p.second) << 16));
    }
};

class CountSquares {
    std::unordered_map<std::pair<int, int>, int, PairHash> m_Map;

   public:
    CountSquares() {}

    void add(vector<int> point) { m_Map[{point[0], point[1]}]++; }

    int count(vector<int> point) {
        int res = 0;
        int px = point[0];
        int py = point[1];
        for (auto const& [key, count] : m_Map) {
            int x = key.first;
            int y = key.second;

            if (abs(x - px) != abs(y - py) || x == px || y == py) 
                continue;

            if (m_Map.contains({px, y}) && m_Map.contains({x, py})) {
                res += count * m_Map[{px, y}] * m_Map[{x, py}];
            }
        }

        return res;
    }
};

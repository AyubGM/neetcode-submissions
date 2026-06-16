class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::unordered_map<string, std::vector<string>> groups;
        for(const auto& s: strs)
        {
            std::string key = s;
            std::sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        for(auto& pair: groups)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> res;
        std::unordered_map<string, std::vector<string>> groups;

        for(auto& s : strs)
        {
            std::string key = s;
            std::sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        for(auto sPair : groups)
        {
            res.push_back(sPair.second);
        }

        return res;

    }
};

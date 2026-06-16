class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string res = "";
        for (const auto& s : strs) {
            res += std::to_string(s.size()) + "#" + s;
        }
        return res;
    }
    // 3#cat4#POPO
    vector<string> decode(string s) {
        std::vector<string> res;

        int i = 0;

        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int size = std::stoi(s.substr(i, j - i));
            i = j + 1;

            std::string str = "";
            int count = 0;
            while (count < size) {
                str += s[i];
                i++;
                count++;
            }
            res.push_back(str);
        }

        return res;
    }
};

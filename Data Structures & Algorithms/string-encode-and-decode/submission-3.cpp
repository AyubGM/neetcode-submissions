class Solution {
   public:
    string encode(vector<string>& strs) {
        std::string res = "";

        for (auto& str : strs) {
            res += std::to_string(str.size()) + "#" + str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int start = 0;
        while (start < s.size()) {
            int sizeIndex = start;
            while (s[sizeIndex] != '#') sizeIndex++;
            
            int size = std::stoi(s.substr(start, sizeIndex - start));

            start = sizeIndex + 1;

            int end = start + size;

            std::string str = s.substr(start, size);

            res.push_back(str);

            start = end;
        }

        return res;
    }
};

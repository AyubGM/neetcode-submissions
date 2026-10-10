class Solution {
   public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int res{0};

        int l{0};
        int maxf{0};

        for (size_t r{0}; r < s.size(); r++) {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }

            res = std::max(res, int(r - l + 1));
        }

        return res;
    }
};

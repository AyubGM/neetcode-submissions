class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;

        int l = 0;
        int mWindow = 0;
        for (int r{0}; r < s.size(); r++) {
            while (seen.contains(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);

            mWindow = std::max(mWindow, r - l + 1);
        }

        return mWindow;
    }
};

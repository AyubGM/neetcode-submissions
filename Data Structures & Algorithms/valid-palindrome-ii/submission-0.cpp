class Solution {
    bool isPalindromeRange(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
   public:
    bool validPalindrome(string s) {
        bool IsDeleted = false;

        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                // Try skipping s[l] OR skipping s[r]
                return isPalindromeRange(s, l + 1, r) || isPalindromeRange(s, l, r - 1);
            }
            l++;
            r--;
        }

        return true;
    }
};
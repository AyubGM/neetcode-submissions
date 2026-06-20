class Solution {
    void CountFromCenter(const string& s, int left, int right, int& count)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
    }
   public:
    int countSubstrings(string s) {
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            CountFromCenter(s, i, i, count);
            CountFromCenter(s, i, i + 1, count);
        }

        return count;
    }
};

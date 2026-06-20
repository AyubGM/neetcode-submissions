class Solution {
    int ExpandAroundCenter(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        

        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int len1 = ExpandAroundCenter(s, i, i);

            int len2 = ExpandAroundCenter(s, i, i + 1);

            int len = std::max(len1, len2);

            if (len > maxLength)
            {
                maxLength = len;

                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};

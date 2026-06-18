class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> countT;
        for (char c : t) countT[c]++;

        unordered_map<char, int> window;

        int have = 0, need = countT.size(); 
        int minLen = INT_MAX;
        int minLeft = 0;

        int l = 0;

        for (int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if (countT.contains(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need)
            {
                if (r - l + 1 < minLen)
                {
                    minLen = r - l + 1;
                    minLeft = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
       
    }
};

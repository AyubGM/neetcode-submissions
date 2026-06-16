class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int frq[26] = {0};

        for(char c : s1)
        {
            frq[c - 'a']++;
        }

        int l = 0;
        for(int r = 0; r < s2.length(); r++ )
        {
            frq[s2[r] - 'a']--;

            while (frq[s2[r] - 'a'] < 0)
            {
                frq[s2[l] - 'a']++;
                l++;
            }
            int windowSize = r - l + 1;
            if(windowSize == s1.length())
            return true;
        }

        return false;
    }
};

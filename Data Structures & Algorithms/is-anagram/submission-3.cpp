class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> frq(26, 0);

        for(char c : s)
        {
            frq[c - 'a']++;
        }

        for(char c : t)
        {
            if(frq[c - 'a'] == 0)
            {
                return false;
            }

            frq[c - 'a']--;
        }
        return true;
    }
};

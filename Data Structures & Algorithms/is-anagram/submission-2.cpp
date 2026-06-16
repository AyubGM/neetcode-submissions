class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        // std::sort(s.begin(), s.end());
        // std::sort(t.begin(), t.end());

        // return s == t;

        std::unordered_map<char, int> frq;

        for(auto c : s)
        {
            frq[c]++;
        }

         for(auto c : t)
        {
            if(frq[c] == 0)
            {
                return false;
            } 
            frq[c]--;
        }
        return true;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> cSet;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++)
        {
           while(cSet.count(s[r]))
            {
                cSet.erase(s[l]); // Fixed: changed [] to ()
                l++;
            }
            cSet.insert(s[r]);
            res = std::max(res, (r - l + 1));
        }

        return res;
    }
};

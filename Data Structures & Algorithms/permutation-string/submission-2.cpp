class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       std::unordered_map<char, int> frq;

       for(char c : s1) frq[c]++;

       int l = 0;
       
       for(int r = 0; r < s2.size(); r++)
       {
         frq[s2[r]]--;
         
         while (frq[s2[r]] < 0)
         {
            frq[s2[l]]++;
            l++;
         }

         int window = r - l + 1;

         if (window == s1.size())
         return true;
       }

       return false;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
      std::unordered_map<char, int> count;        
      int res = 0;
      int l = 0;
      int maxF = 0;
      for (int r = 0; r < s.size(); r++)
      {
         count[s[r]]++;

        maxF = std::max(maxF, count[s[r]]);

         int window = r - l + 1;

         if (window -maxF > k)
         {
           count[s[l]]--;
           l++;
         }

         res = std::max(res, r - l + 1);

      }

      return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
      std::unordered_map<char, int> count;        
      int res = 0;
      int l = 0;

      for (int r = 0; r < s.size(); r++)
      {
         count[s[r]]++;

         auto max = std::max_element(count.begin(), count.end(),
         []( const auto& a, const auto& b){
          return a.second < b.second;
         });

         int window = r - l + 1;

         if (window - max->second > k)
         {
           count[s[l]]--;
           l++;
         }

         res = std::max(res, r - l + 1);

      }

      return res;
    }
};

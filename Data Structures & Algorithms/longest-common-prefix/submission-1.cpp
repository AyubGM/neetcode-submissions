class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        const string& base = strs[0];

        for (int i = 0; i < base.size(); i++)
        {
          char c = base[i];

          for (int j = 1; j < strs.size(); j++)
          {
            if (i >= strs[j].size() || strs[j][i] != c)
            {
                return base.substr(0, i);
            }
          }  
        }

        return base;
    }
};
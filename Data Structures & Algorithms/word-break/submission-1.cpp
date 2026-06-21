class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        std::vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && wordSet.contains(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};

class Solution {
    bool isPalindrome(const string& str) {
        int low = 0, high = str.size() - 1;
        while (low < high) {
            if (str[low++] != str[high--]) return false;
        }
        return true;
    }
    void Dfs(int start, vector<string>& sub, vector<vector<string>>& res,
             const string& s) {
        if (start == s.size()) {
            res.push_back(sub);
            return;
        }

        string subS = "";
        for (int i = start; i < s.size(); i++) {
            subS += s[i];

            if (isPalindrome(subS)) {
                sub.push_back(subS);
                Dfs(i + 1, sub, res, s);
                sub.pop_back();
            }

        }
    }

   public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        Dfs(0, sub, res, s);

        return res;
    }
};

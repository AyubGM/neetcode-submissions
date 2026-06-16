class Solution {
    void Dfs(vector<string>& res, string& sub, int open, int close, int n) {
        if (sub.size() == (n * 2)) {
            res.push_back(sub);
            return;
        }

        if (open < n) {
            sub.push_back('(');
            Dfs(res, sub, open + 1, close, n);
            sub.pop_back();
        }

        if (close < open) {
            sub.push_back(')');
            Dfs(res, sub, open, close + 1, n);
            sub.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sub;

        Dfs(res, sub, 0, 0, n);

        return res;
    }
};

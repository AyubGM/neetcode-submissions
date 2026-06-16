class Solution {
    void Dfs(int start, vector<vector<int>>& res, vector<int>& sub, const vector<int>& candidates,
             int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            sub.push_back(candidates[i]);
            Dfs(i + 1, res, sub, candidates, target - candidates[i]);
            sub.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        Dfs(0, res, sub, candidates, target);
        return res;
    }
};

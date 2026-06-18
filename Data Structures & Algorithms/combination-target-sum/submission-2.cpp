class Solution {
    void Dfs(int start, vector<vector<int>>& res, const vector<int>& nums, vector<int>& sub,
             int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            Dfs(i, res, nums, sub, target - nums[i]);
            sub.pop_back();
        }
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        Dfs(0, res, nums, sub, target);

        return res;
    }
};

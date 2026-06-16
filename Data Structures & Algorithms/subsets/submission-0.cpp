class Solution {
    void Dfs(int start ,const vector<int>& nums, vector<vector<int>>& res, std::vector<int>& sub) {
        
        res.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            Dfs(i + 1 ,nums, res, sub);
            sub.pop_back();
        }
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        Dfs(0 ,nums, res, sub);
        return res;
    }
};

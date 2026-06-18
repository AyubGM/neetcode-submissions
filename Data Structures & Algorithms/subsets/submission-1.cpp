class Solution {
   void Dfs (int index, vector<int> sub ,vector<vector<int>>& res,const vector<int>& nums) 
   {
    res.push_back(sub);
    for (int i = index; i < nums.size(); i++)
    {
        sub.push_back(nums[i]);
        Dfs(i + 1, sub, res, nums);
        sub.pop_back();
    }
   }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> sub;
        Dfs(0, sub, res, nums);
        return res;
    }
};

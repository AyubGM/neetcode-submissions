class Solution {
    void Dfs(int start ,std::vector<std::vector<int>>& res, std::vector<int>& sub,const vector<int>& nums)
    {
        res.push_back(sub);

        for(int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            sub.push_back(nums[i]);
            Dfs(i + 1 ,res, sub, nums);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      std::vector<std::vector<int>> res;
      std::sort(nums.begin(), nums.end());
      std::vector<int> sub;

      Dfs(0 ,res, sub, nums);

      return res;


    }
};

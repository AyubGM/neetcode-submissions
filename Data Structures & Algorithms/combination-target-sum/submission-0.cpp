class Solution {
    void Dfs(int start,vector<vector<int>>& res ,const vector<int>& nums, vector<int>& sub,int target)
    {
        int sum = 0;
        for (int s : sub) sum += s;

        if (sum == target)
        {
             res.push_back(sub);
             return;
        } 
        else if(sum > target) return;
        else {

            for(int i = start; i < nums.size(); i++)
            {
                sub.push_back(nums[i]);
                Dfs(i, res , nums, sub, target);
                sub.pop_back();
            }

        }
 
           

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub;
        Dfs(0 ,res, nums, sub,target);

        return res;
    }
};

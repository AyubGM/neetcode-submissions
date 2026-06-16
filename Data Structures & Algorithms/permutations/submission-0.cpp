class Solution {
    void Dfs(vector<vector<int>>& res, vector<int>& sub, const vector<int>& nums, vector<bool>& visited)
    {
        if(sub.size() == nums.size())
        {
            res.push_back(sub);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
           if (visited[i]) {
                continue;
            }

            visited[i] = true;

            sub.push_back(nums[i]);
            Dfs(res, sub, nums, visited);
            sub.pop_back();
            visited[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        vector<bool> visited(nums.size(), false);
        Dfs(res, sub, nums, visited);

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
           if (nums[i] > 0) break;

           if (i > 0 && nums[i] == nums[i - 1]) continue;

           int left = i + 1;
           int right = n -1;

           while (left < right)
           {

             int val = nums[i] + nums[left] + nums[right];

             if(val > 0)
             {
                right--;
                continue;
             }

             if (val < 0 )
             {
                left++;
                continue;
             }

            res.push_back({nums[i], nums[left], nums[right]});
            while(left < right && nums[left] == nums[left + 1]) left++;
            while(left < right && nums[right] == nums[right - 1]) right--;
            left++;
            right--;

           }

        }

        return res;

    }
};

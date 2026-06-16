class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        std::sort(nums.begin(), nums.end());

        int longest = 1;
        int sq = 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1]) {
                continue;
            }

            if( nums[i + 1] - nums[i]  == 1)
            {
                sq++;
            } else
            {
                longest = std::max(longest, sq);
                sq = 1;
            }
        }

        return std::max(longest, sq);
    }
};

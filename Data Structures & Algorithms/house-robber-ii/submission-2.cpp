class Solution {
    int robLinear(const std::vector<int>& nums, int start, int end) {
        int robBeforePrevious = 0;
        int robPrevious = 0;

        for (int i = start; i <= end; i++) {
            int currentMax = std::max(robBeforePrevious + nums[i], robPrevious);
            robBeforePrevious = robPrevious;
            robPrevious = currentMax;
        }

        return robPrevious;
    }
public:
    int rob(vector<int>& nums) {

       int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return std::max(nums[0], nums[1]);

        int skipLastHouse = robLinear(nums, 0, n - 2);
        int skipFirstHouse = robLinear(nums, 1, n - 1);
        return std::max(skipLastHouse, skipFirstHouse);
    }
};

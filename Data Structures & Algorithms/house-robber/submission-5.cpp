class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        nums.push_back(0);
        nums.push_back(0);

        for (int i = nums.size() - 4; i >= 0; i--) {
            nums[i] += std::max(nums[i + 2], nums[i + 3]);
        }

        return std::max(nums[0], nums[1]);
    }
};
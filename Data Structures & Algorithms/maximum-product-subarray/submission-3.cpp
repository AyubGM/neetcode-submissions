class Solution {
  
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int globalMax = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int num = nums[i];

            if (num < 0)
            {
                std::swap(currentMax, currentMin);
            }

            currentMax = std::max(num, currentMax * num);
            currentMin = std::min(num, currentMin * num);

            globalMax = std::max(globalMax, currentMax);
        }

        return globalMax;
    }
};

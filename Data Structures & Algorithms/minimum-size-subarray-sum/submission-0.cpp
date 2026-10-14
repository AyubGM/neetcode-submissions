class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = 0;
        bool firstTime = true;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            int j = i;

            while (sum < target && j < nums.size())
            {
                sum += nums[j];
                j++;
            }

            if (sum < target) return minSize;
            
            int window = j - i;
            if (firstTime)
            {
                minSize = window;
                firstTime = false;
            }
            minSize = std::min(minSize, window);
            
        }

        return minSize;
    }
};
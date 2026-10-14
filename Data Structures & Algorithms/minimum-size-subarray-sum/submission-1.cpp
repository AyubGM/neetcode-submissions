class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minSize = INT_MAX;
        int sum = 0;
        int r = 0;
        int l = 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum >= target)
            {
                int window = r - l + 1;
                minSize = std::min(minSize, window);
                sum -= nums[l];
                l++;
            }  
            r++;
        }

        return minSize == INT_MAX ? 0 : minSize;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());

        int longestCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if (!set.contains(num - 1))
            {
                int currCount = 1;
                int curr = num;
                while (set.contains(curr + 1))
                {
                    currCount++;
                    curr++;
                }

                longestCount = std::max(longestCount, currCount);
                
            }

        }

        return longestCount;
    }
};

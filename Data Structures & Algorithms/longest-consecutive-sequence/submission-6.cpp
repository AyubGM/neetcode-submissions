class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for(int num : numSet)
        {
            if (!numSet.contains(num - 1))
            {
                int currentStreak = 1;

                int currentNum = num;
                while(numSet.contains(currentNum + 1))
                {
                    currentStreak++;
                    currentNum++;
                } 
                longestStreak = std::max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
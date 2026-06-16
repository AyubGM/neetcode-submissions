class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : numSet) {

            // if there is no smaller number than our current number
            // than we found our starting point
            if (!numSet.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                
                // we found the next number in the sequance
                // so we update our streak
                while(numSet.count(currentNum + 1))
                {
                  currentNum = currentNum + 1;
                  currentStreak++;
                }
             longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
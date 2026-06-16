class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : numSet) {

            if(!numSet.count(num - 1))
            {
                int currNum = num;
                int current = 0;

                while(numSet.count(currNum))
                { 
                    currNum = currNum + 1;
                    current++;
                }
              longestStreak = std::max(longestStreak, current);
            }
        }

        return longestStreak;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. Put everything in a set for O(1) lookups
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {

            if (numSet.find(n - 1) == numSet.end()) {
                int currentNum = n;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = std::max(longest, currentStreak);
            }
        }

        return longest;
    }
};
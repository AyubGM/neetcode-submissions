class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int op = numbers[left] + numbers[right];

            if (op > target) {
                right--;
            }
            else if (op < target) {
                left++;
            } else
            {
                return {left + 1, right + 1};
            }
        }

        return {};
    }
};

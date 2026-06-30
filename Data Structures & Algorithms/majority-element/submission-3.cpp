class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];

        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (count == 0) {
                element = nums[i];
                count = 1;
            } else if (nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }

        

        return element;
    }
};
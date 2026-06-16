class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int times = nums.size();
        int slow = 0;
        int fast = 0;
        int n = nums.size();
        while (times)
        {
            if(slow == fast)
            {
                fast = (fast + 1) % n;
            }

            if(nums[slow] == nums[fast])
            return nums[slow];

            slow = (slow + 1) % n;
            fast = (fast + 2) % n;

            if(slow == 0)
            {
                times--;
            }

        }
        return nums[slow];
    }
};

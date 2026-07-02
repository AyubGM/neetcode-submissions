class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::array<int, 3> frq{0, 0, 0};

        for (int num : nums)
        {
            frq[num]++;
        }

        int k = 0;
        for (int i = 0; i < frq.size(); i++)
        {
            for (int j = frq[i]; j > 0; --j)
            {
                nums[k++] = i;
            }
        }
    }
};
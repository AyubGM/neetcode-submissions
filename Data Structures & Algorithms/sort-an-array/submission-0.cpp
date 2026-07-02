class Solution {
    void Merg(std::vector<int>& nums, int start, int mid, int end)
    {
        std::vector<int> temp (end - start + 1);

        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] =  nums[i++];
            } else
            {
                temp[k++] =  nums[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] =  nums[i++];
        }

        while (j <= end)
        {
           temp[k++] =  nums[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            nums[start + p] = temp[p];
        }
    }

    void MergSort(vector<int>& nums, int start, int end)
    {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        MergSort(nums, start, mid);
        MergSort(nums, mid + 1, end);

        Merg(nums, start, mid, end);
        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        
        MergSort(nums, 0, nums.size() -1);

        return nums;
    }
};
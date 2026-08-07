class Solution {
    void MergSort(vector<int>& nums, int start, int end)
    {
        if (start >= end) return;

        int mid = start + (end - start) / 2;

        MergSort(nums, start, mid);
        MergSort(nums, mid + 1, end);

        Merg(nums, start, mid, end);
    }

    void Merg(vector<int>& nums, int start, int mid, int end)
    {
        std::vector<int> temp( end - start  + 1);
        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end)
        {
            if (nums[i] <= nums[j])
            {
                temp[k] = nums[i];
                i++;
            } else 
            {
                temp[k] = nums[j];
                j++;
            }
            k++;
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }

        while (j <= end) {
            temp[k++] = nums[j++];
        }

        for (int p = 0; p < temp.size(); ++p) {
            nums[start + p] = temp[p];
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        
        MergSort(nums, 0, nums.size()-1);

        return nums;
    }
};
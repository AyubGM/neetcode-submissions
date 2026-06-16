class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       std::vector<int> res(nums.size(), 1);

        int leftProd = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            res[i] *= leftProd;
            leftProd *= nums[i]; 
        }


        int rightProd = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            res[i] *= rightProd;
            rightProd *= nums[i]; 
        }
       return res;
    }
};

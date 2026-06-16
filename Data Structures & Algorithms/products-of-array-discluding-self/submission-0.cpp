class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prods(size);

        for(int i = 0; i < size; i++)
        {
            int prod = 1;
            for(int j = 0; j < size ; j++)
            {
                if(j != i)
                {
                    prod *= nums[j];
                }

            }
            prods[i] = prod;
        }
        return prods;
    }
};

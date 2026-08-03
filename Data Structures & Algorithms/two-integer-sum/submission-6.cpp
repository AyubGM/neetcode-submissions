class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> complements;

        for (int i = 0; i < nums.size(); i++)
        {
            int complment = target - nums[i];

            if (complements.contains(complment))
            {
                return {complements[complment] ,i};
            }

            complements[nums[i]] = i;
        }
    } 
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     std::unordered_map<int,int> prefixCounts;

     prefixCounts[0] = 1;
     int res = 0;
     int currSum = 0;

     for (int num : nums)
     {
        currSum += num;

        if (prefixCounts.contains(currSum - k)) 
        {
            res += prefixCounts[currSum - k];
        }
        prefixCounts[currSum]++;
     }
    return res;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    //    unordered_set<int> seen;
    //    for(int i = 0; i< nums.size();i++)
    //    {
    //     if(seen.find(nums[i]) != seen.end())
    //     {
    //         return true;
    //     }
    //     seen.insert(nums[i]);
    //    }
    //    return false;
    for(int i = 0; i< nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
        if (nums[i] == nums[j]){
            return true;
        }
     }
    }
    return false;
    }
};

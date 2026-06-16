class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      std::unordered_set<int> dupSet;

      for(auto num : nums)
      {

        if(dupSet.count(num))
        {
            return true;
        }

        dupSet.insert(num);
      }

      return false;
    }
};
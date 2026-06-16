class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::unordered_map<int, int> seen;

        for(int i = 0; i < numbers.size(); i++)
        {
            int comp = target - numbers[i];

            if(seen.find(comp) != seen.end())
            {
                return {seen[comp] + 1, i + 1};
            }

            seen[numbers[i]] = i;
        }

        return {};
    }
};

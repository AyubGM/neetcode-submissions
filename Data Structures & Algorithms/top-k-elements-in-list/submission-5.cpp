class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;

        for (auto num : nums) {
            counts[num]++;
        }

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto [key, val] : counts) {
            buckets[val].push_back(key);
        }

        std::vector<int> res;

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                if (k == 0) break;
                k--;
                res.push_back(buckets[i][j]);
            }
        }

        return res;
    }
};

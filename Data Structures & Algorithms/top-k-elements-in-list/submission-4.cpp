class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        std::vector<vector<int>> frq(nums.size() + 1);   
        for(int n : nums)
        {
            counts[n]++;
        }

        for (auto [n, c] : counts)
        {
            frq[c].push_back(n);
        }

        std::vector<int> res;

          for (int i = frq.size() - 1; i > 0; --i) {
            for (int n : frq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }

};
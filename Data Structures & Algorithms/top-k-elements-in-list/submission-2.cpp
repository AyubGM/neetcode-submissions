class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        
        for(int n : nums)
        {
            counts[n]++;
        }

        std::priority_queue<std::pair<int,int>> pq;

        for(auto [n, frq] : counts)
        {
            pq.push({frq, n});
        }

        vector<int> res;
        while(!pq.empty() && k > 0)
        {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return res;
    }
};
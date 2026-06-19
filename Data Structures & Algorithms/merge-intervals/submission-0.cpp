class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        std::sort(intervals.begin(), intervals.end());
        std::vector<int> currentInterval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (currentInterval[1] >= intervals[i][0]) {
                // currentInterval = {std::min(currentInterval[0], intervals[i][0]),
                //                    std::max(currentInterval[1], intervals[i][1])};
                currentInterval[1] = std::max(currentInterval[1], intervals[i][1]);
            } else {
                res.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        res.push_back(currentInterval);
        return res;
    }
};

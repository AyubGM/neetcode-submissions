class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int squared_dist = x * x + y * y;

            pq.push({squared_dist, i});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;
        while (!pq.empty())
        {
            int index = pq.top().second;
            pq.pop();
            res.push_back(points[index]);
        }

        return res;
    }
};

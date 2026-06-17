class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       std::priority_queue<std::pair<int, int>> pq;

        for(int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            int distance = x*x + y*y;

            pq.push({distance, i});

            if (pq.size() > k)
            pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            auto [distance, index] = pq.top(); 
            pq.pop();                          
            
            res.push_back(points[index]);  
        }

        return res;
       

    }
};

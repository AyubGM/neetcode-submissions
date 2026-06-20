struct Node {
    int Dest;
    int Time;

    Node(int dest, int time) : Dest(dest), Time(time) {}
};

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<Node>> graph;

        for (auto& tuple : times) {
            int src = tuple[0];
            int dest = tuple[1];
            int time = tuple[2];

            graph[src].push_back({dest, time});
        }

        std::vector<int> dist(n + 1, 1e9);
        // {accumulated_time, node}
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;
        pq.push({0, k});
        dist[k] = 0;

        int minTime = 0;
        while (!pq.empty()) {
           auto [currentTime, src] = pq.top();
           pq.pop();

           if (currentTime > dist[src]) continue;

           for (const auto& neighbor : graph[src])
           {
             int nextNode = neighbor.Dest;
             int travelTime = neighbor.Time;

             if (dist[src] + travelTime < dist[nextNode])
             {
                dist[nextNode] = dist[src] + travelTime;
                pq.push({dist[nextNode], nextNode});
             }
           }
        }

        int maxDelay = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9) return -1;
            maxDelay = std::max(maxDelay, dist[i]);
        }

        return maxDelay;
    }
};

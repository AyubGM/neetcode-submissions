class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);

        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            adj[u].push_back({v, price});
        }

        vector<int> minPrices(n, INT_MAX);
        minPrices[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;

        while (!q.empty() && stops <= k)
        {
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                auto [currNode, currCost] = q.front();
                q.pop();

                for (const auto& nei : adj[currNode])
                {
                    int nextNode = nei.first;
                    int flightPrice = nei.second;

                    if (currCost + flightPrice < minPrices[nextNode]) {
                        minPrices[nextNode] = currCost + flightPrice;
                        q.push({nextNode, minPrices[nextNode]});
                    }
                }
            }
            stops++;
        }

        return minPrices[dst] == INT_MAX ? -1 : minPrices[dst];
    }
};

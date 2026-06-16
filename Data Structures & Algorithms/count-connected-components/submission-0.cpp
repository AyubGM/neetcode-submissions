class Solution {
    void Dfs(int src, const std::unordered_map<int, std::vector<int>>& graph,
             std::unordered_set<int>& visited) {
        if (visited.contains(src)) {
            return;
        }

        visited.insert(src);

        if (graph.contains(src)) {
            for (int neighbor : graph.at(src)) {
             
               if (!visited.contains(neighbor)) {
                    Dfs(neighbor, graph, visited);
                }
            }
        }
    }

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> graph;

        for (const auto& pair : edges) {
            int src = pair[0];
            int des = pair[1];
            graph[src].push_back(des);
            graph[des].push_back(src);
        }

        int count = 0;
        std::unordered_set<int> visited;

        for (int i = 0; i < n; ++i)
        {
            if (!visited.contains(i))
            {
                count++;
                Dfs(i, graph, visited);
            }
        }


        return count;
    }
};

class Solution {
    bool Dfs(int src, int parent, const std::unordered_map<int, std::vector<int>>& graph,
             std::unordered_set<int>& visited) {
        if (visited.contains(src)) {
            return false;
        }

        visited.insert(src);
        if (graph.contains(src)) {
            for (int neighbor : graph.at(src)) {
                if (neighbor == parent) {
                    continue;
                }
                if (!Dfs(neighbor, src,graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }

   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> graph;

        for (const auto& pair : edges) {
            int src = pair[0];
            int des = pair[1];
            graph[src].push_back(des);
            graph[des].push_back(src);
        }

        std::unordered_set<int> visited;
        if (!Dfs(0, -1, graph, visited)) {
            return false;
        }

        return visited.size() == n;
    }
};

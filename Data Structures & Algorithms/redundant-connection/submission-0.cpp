class Solution {
    bool Dfs(int src, int target,int parent,const std::unordered_map<int, std::vector<int>>& graph,
             std::unordered_set<int>& visited) {

        if (src == target) {
            return true;
        }

        visited.insert(src);

        if(graph.contains(src))
        {
              
            for (int neighbor : graph.at(src))
            {
                if (neighbor == parent) continue; 
                if (!visited.contains(neighbor)) {
                    if (Dfs(neighbor, target, src, graph, visited)) {
                        return true;
                    }
                }
            }

        }

        return false;

    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> graph;

        for (const auto& pair : edges) {
            int src = pair[0];
            int des = pair[1];

            std::unordered_set<int> visited;

            if(graph.contains(src) && graph.contains(des) && Dfs(src, des, -1, graph, visited))
            {
                return pair;
            }

            graph[src].push_back(des);
            graph[des].push_back(src);
        }


        



    }
};

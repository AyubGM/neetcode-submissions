class Solution {
    bool Dfs(int course, const std::unordered_map<int, std::vector<int>>& graph,
             std::vector<int>& res, std::unordered_set<int>& visiting,
             std::unordered_set<int>& visited) {



        if (visiting.contains(course)) {
            return false;
        }
       
        if (visited.contains(course)) {
            return true;
        }
        visiting.insert(course);

        if (graph.contains(course)) {
            for (int neighbor : graph.at(course)) {
               if (!Dfs(neighbor, graph, res, visiting, visited)) {
                    return false; 
                }
            }
        }
        visiting.erase(course);
        visited.insert(course);
        res.push_back(course);
        
        return true;
    }

   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> graph;

        for (const auto& pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            graph[course].push_back(prereq);
        }

        std::vector<int> res;
        std::unordered_set<int> visiting;
        std::unordered_set<int> visited;
        for (int i = 0; i < numCourses; ++i) {
           if (!Dfs(i, graph, res, visiting, visited)) {
                return {};
            }
        }

        return res;
    }
};

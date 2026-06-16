
class Solution {
    bool Dfs(int course, 
             const std::unordered_map<int, std::vector<int>>& graph, 
             std::unordered_set<int>& visiting, 
             std::unordered_set<int>& visited)
    {
        if(visiting.contains(course))
        {
            return false;
        }

        if (visited.contains(course))
        {
            return true;
        }

        visiting.insert(course);

       if (graph.contains(course)) {
            for (int neighbor : graph.at(course)) {
                if (!Dfs(neighbor, graph, visiting, visited)) {
                    return false;
                }
            }
        }

        visiting.erase(course);
        visited.insert(course);

        return true;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> graph;
        
        for(const auto& pair :prerequisites)
        {
            int course = pair[0];
            int prereq = pair[1];
            graph[course].push_back(prereq);
        }  

        std::unordered_set<int> visiting;
        std::unordered_set<int> visited;
        for(int i = 0; i < numCourses; ++i)
        {

            if(!Dfs(i, graph, visiting, visited))
            {
                return false;
            }

        }

        return true;

    }
};

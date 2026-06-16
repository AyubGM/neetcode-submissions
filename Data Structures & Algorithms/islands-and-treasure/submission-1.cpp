class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int Rows = grid.size();
        int Cols = grid[0].size();

        std::queue<std::pair<int, int>> q;

        for (size_t r = 0; r < Rows; ++r) {
            for (size_t c = 0; c < Cols; ++c) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr;
                int nc = c + dc;


                if (std::min(nr, nc) < 0 || nr >= Rows || nc >= Cols || grid[nr][nc] != 2147483647 )
                {
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};

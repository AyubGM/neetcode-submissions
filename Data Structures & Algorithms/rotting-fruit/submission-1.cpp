class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int Rows = grid.size();
        int Cols = grid[0].size();
        std::queue<std::pair<int, int>> rottenQ;
        int freshOranges = 0;

        for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Cols; c++) {
                if (grid[r][c] == 2) {
                    rottenQ.push({r, c});
                } else if (grid[r][c] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0) return 0;

        int timeElapsed = 0;

        std::array<std::pair<int, int>, 4> dirs = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        while (!rottenQ.empty() && freshOranges > 0) {
            int qSize = rottenQ.size();
            timeElapsed++;
            

            for (int i = 0; i < qSize; i++) {
                auto [r, c] = rottenQ.front();
                rottenQ.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (min(nr, nc) < 0 || nr >= Rows || nc >= Cols || grid[nr][nc] != 1) {
                        continue;
                    }

                    grid[nr][nc] = 2;
                    freshOranges--;
                    rottenQ.push({nr, nc});
                }
            }
        }

       return freshOranges == 0 ? timeElapsed : -1;
    }
};

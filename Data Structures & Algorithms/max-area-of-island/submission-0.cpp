class Solution {
    int Dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int Rows = grid.size();
        int Cols = grid[0].size();

        if (min(r, c) < 0 || r >= Rows || c >= Cols || visited[r][c] || grid[r][c] == 0) {
            return 0;
        }

        visited[r][c] = true;
        int count = 1;

        count += Dfs(r + 1, c, grid, visited);
        count += Dfs(r - 1, c, grid, visited);
        count += Dfs(r, c + 1, grid, visited);
        count += Dfs(r, c - 1, grid, visited);

        return count;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Rows = grid.size();
        int Cols = grid[0].size();
        std::vector<std::vector<bool>> visited(Rows, vector<bool>(Cols, false));
        int maxArea = 0;

        for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    int currArea = Dfs(r, c, grid, visited);
                    maxArea = std::max(maxArea, currArea);
                }
            }

        }

        return maxArea;
    }
};

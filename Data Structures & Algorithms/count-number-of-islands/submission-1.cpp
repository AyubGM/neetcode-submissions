class Solution {
        int Rows = 0;
        int Cols = 0;
    void Dfs(int r, int c, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        

        if (min(c, r) < 0 || r >= Rows || c >= Cols) {
            return;
        }

        if (grid[r][c] == '0' || visited[r][c]) return;

        visited[r][c] = true;

        Dfs(r + 1, c, grid, visited);
        Dfs(r - 1, c, grid, visited);
        Dfs(r, c + 1, grid, visited);
        Dfs(r, c - 1, grid, visited);
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        Rows = grid.size();
        Cols = grid[0].size();
        vector<vector<bool>> visited(Rows, vector<bool>(Cols, false));
        int count = 0;

        for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Cols; c++) {
                if (grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    Dfs(r, c, grid, visited);
                }
            }
        }

        return count;
    }
};

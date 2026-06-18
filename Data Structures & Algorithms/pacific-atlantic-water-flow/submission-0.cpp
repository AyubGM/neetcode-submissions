class Solution {
    int Rows = 0;
    int Cols = 0;
    void Dfs(int r, int c, vector<vector<bool>>& visited, int prevHight,
             vector<vector<int>>& heights) {
        if (r < 0 || r >= Rows || c < 0 || c >= Cols || heights[r][c] < prevHight ||
           visited[r][c])
            return;

        visited[r][c] = true;

        Dfs(r + 1, c, visited, heights[r][c], heights);
        Dfs(r - 1, c, visited, heights[r][c], heights);
        Dfs(r, c + 1, visited, heights[r][c], heights);
        Dfs(r, c - 1, visited, heights[r][c], heights);
    }

   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        Rows = heights.size();
        Cols = heights[0].size();

        vector<vector<bool>> Pacific(Rows, vector<bool>(Cols, false));
        vector<vector<bool>> Atlantic(Rows, vector<bool>(Cols, false));

        for (int c = 0; c < Cols; c++) {
            Dfs(0, c, Pacific, heights[0][c], heights);
            Dfs(Rows - 1, c, Atlantic, heights[Rows - 1][c], heights);
        }

        for (int r = 0; r < Rows; r++) {
            Dfs(r, 0, Pacific, heights[r][0], heights);
            Dfs(r, Cols - 1, Atlantic, heights[r][Cols - 1], heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < Rows; r++)
        {
             for (int c = 0; c < Cols; c++)
             {
                if (Pacific[r][c] && Atlantic[r][c])
                res.push_back({r,c});
             }
        }

        return res;
    }
};

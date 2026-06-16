class Solution {
    bool Dfs(int r, int c, int index, const vector<vector<char>>& board, const string& word,
             vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }

        int Rows = board.size();
        int Cols = board[0].size();

        if (r < 0 || r >= Rows || c < 0 || c >= Cols || visited[r][c] ||
            board[r][c] != word[index]) {
            return false;
        }
        visited[r][c] = true;
        bool found = Dfs(r + 1, c, index + 1, board, word, visited) ||
                     Dfs(r - 1, c, index + 1, board, word, visited) ||
                     Dfs(r, c + 1, index + 1, board, word, visited) ||
                     Dfs(r, c - 1, index + 1, board, word, visited);

        visited[r][c] = false;

        return found;
    }

   public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        std::vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == word[0] && Dfs(r, c, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

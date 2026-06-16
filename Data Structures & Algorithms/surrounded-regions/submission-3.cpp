struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // Combine hashes (using a standard bit-shifting formula to avoid collisions)
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

class Solution {
    void Dfs(int r, int c, vector<vector<char>>& board,
            std::unordered_set<std::pair<int, int>, pair_hash>& edgeOs) {
                int Rows = board.size();
                int Cols = board[0].size();
                if(r < 0 || c < 0 || r >= Rows || c >= Cols || board[r][c] == 'X')
                {
                    return;
                }
                if(edgeOs.contains({r,c}))
                {
                    return;
                }
                edgeOs.insert({r, c});

                Dfs(r + 1, c, board, edgeOs);
                Dfs(r - 1, c, board, edgeOs);
                Dfs(r, c + 1, board, edgeOs);
                Dfs(r, c - 1, board, edgeOs);

             }

   public:
    void solve(vector<vector<char>>& board) {
        int Rows = board.size();
        int Cols = board[0].size();
        std::unordered_set<std::pair<int, int>, pair_hash> edgeOs;

        for (int c = 0; c < Cols; c++) {
            if (board[0][c] == 'O') {
                edgeOs.insert({0, c});
            }

            if (board[Rows - 1][c] == 'O') {
                edgeOs.insert({Rows - 1, c});
            }
        }
        for (int r = 0; r < Rows; r++) {
            if (board[r][0] == 'O') {
                edgeOs.insert({r, 0});
            }

            if (board[r][Cols - 1] == 'O') {
                edgeOs.insert({r, Cols - 1});
            }
        }

       for (int r = 0; r < Rows; r++) {
            for (int c = 0; c < Cols; c++) {
                if (r == 0 || r == Rows - 1 || c == 0 || c == Cols - 1) {
                    if (board[r][c] == 'O') {
                        edgeOs.erase({r, c});
                        Dfs(r, c, board, edgeOs);
                    }
                }
            }
        }

        for (int r = 1; r < Rows - 1; r++) {
            for (int c = 1; c < Cols - 1; c++) {
                if (board[r][c] == 'O' && !edgeOs.contains({r, c})) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};

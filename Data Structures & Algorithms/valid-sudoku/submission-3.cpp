class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        std::unordered_set<char> Rows[9];
        std::unordered_set<char> Cols[9];
        std::unordered_set<char> Mid[9];

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                char val = board[r][c];
                if(val == '.')
                {
                    continue;
                }

                int mid = (r/3) * 3 + (c/3);

                if (Rows[r].contains(val) || Cols[c].contains(val) ||                 Mid[mid].contains(val))
                {
                    return false;
                }

                Rows[r].insert(val);
                Cols[c].insert(val);
                Mid[mid].insert(val);
            }
        }

        return true;

        
    }
};

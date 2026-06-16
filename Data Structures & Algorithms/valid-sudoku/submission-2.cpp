class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> Rows[9];
        std::unordered_set<char> Cols[9];
        std::unordered_set<char> Squares[9];

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                int value = board[i][j];

                if (value == '.')
                {
                    continue;
                }

                int sIndex = (i/3) * 3 + (j/3);
                if(Rows[i].count(value) || Cols[j].count(value) || Squares[sIndex].count(value))
                return false;

                Rows[i].insert(value);
                Cols[j].insert(value);
                Squares[sIndex].insert(value);
            }
        }

        return true;
    }
};

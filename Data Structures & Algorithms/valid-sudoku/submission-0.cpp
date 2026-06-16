class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> squars[9];

        for(int i = 0; i < 9; i++)
        {
             for(int j = 0; j < 9; j++)
             {
                char val = board[i][j];
                if(val == '.')
                continue;

                int sIndex = (i/3) * 3 + (j/3);

                if(rows[i].count(val) || cols[j].count(val) || squars[sIndex].count(val))
                return false;

                rows[i].insert(val);
                cols[j].insert(val);
                squars[sIndex].insert(val);
             }
        }

        return true;
    }
};

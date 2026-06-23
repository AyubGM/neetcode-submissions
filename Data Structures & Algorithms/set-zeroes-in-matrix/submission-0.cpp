class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();
        bool rowZero = false;

        for (int r = 0; r < Rows; r++)
        {
            for (int c = 0; c < Cols; c++)
            {
                if (matrix[r][c] == 0)
                {
                    matrix[0][c] = 0;
                    if (r > 0)
                        matrix[r][0] = 0;
                    else rowZero = true;
                }
            }
        }

        for (int r = 1; r < Rows; r++)
        {
            for (int c = 1; c < Cols; c++)
            {
                if (matrix[0][c] == 0 || matrix[r][0] == 0)
                {
                    matrix[r][c] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int r = 0; r < Rows; r++)
            {
                matrix[r][0] = 0;
            }
        }

        if (rowZero)
        {
            for (int c = 0; c < Cols; c++)
            {
                matrix[0][c] = 0;
            }
        }

    }
};

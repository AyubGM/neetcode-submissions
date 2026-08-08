class NumMatrix {
    vector<vector<int>> m_Prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        int rows = matrix.size();
        int cols = matrix[0].size();

        m_Prefix.assign(rows + 1, std::vector<int>(cols + 1, 0));

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                m_Prefix[r + 1][c + 1] = matrix[r][c]
                + m_Prefix[r][c + 1]
                + m_Prefix[r + 1][c]
                - m_Prefix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_Prefix[row2 + 1][col2 + 1]
        - m_Prefix[row1][col2 + 1]
        - m_Prefix[row2 + 1][col1]
        + m_Prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
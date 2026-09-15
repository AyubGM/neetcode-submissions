class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();
        int l = 0;
        int r = Rows * Cols -1;

        while ( l <= r)
        {
            int m = l + (r - l) / 2;

            int row = m / Cols;
            int col = m % Cols; 

            if (target > matrix[row][col]) {
                l = m + 1;
            } else if (target < matrix[row][col]) {
                r = m - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

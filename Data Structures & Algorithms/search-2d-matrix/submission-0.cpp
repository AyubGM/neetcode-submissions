class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

         int left = 0;
         int right = (ROWS * COLS) - 1;

         while (left <= right)
         {
            int middle = left + (right - left) / 2;

            int r = middle / COLS;
            int c = middle % COLS;
            int value = matrix[r][c];

            if (value == target) {
                return true;
            } 
            else if (value > target) {
                right = middle - 1; 
            } 
            else {
                left = middle + 1;  
            }
         }

         return false;

      
    }
};

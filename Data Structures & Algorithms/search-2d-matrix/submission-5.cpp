class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int Rows = matrix.size();
        const int Cols = matrix[0].size();
        const int Elements = Cols * Rows;

        int l = 0;
        int r = Elements - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            int row = mid / Cols;
            int col = mid % Cols;

            int val = matrix[row][col];

            if (val > target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            }

            else {
                return true;
            }
        }

            return false;
        }
    };

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;

        int right = 0;

        for (int p : piles) {
            right = std::max(right, p);
        }

        int res = right;

        while (left <= right) {
           int mid = (left + right) / 2;

            int totalHours = 0;
            for (int p : piles)
            {
                totalHours += (p + mid - 1) / mid;
            }

            if ( totalHours <= h)
            {
                res = mid;
                right = mid -1;
            } else
            {
                left = mid + 1;
            }

        }
        return res;
    }
};

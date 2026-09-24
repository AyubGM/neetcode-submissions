class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r = std::reduce(weights.begin(), weights.end());
        int res = r;
        // 1 , 2, 3, 4
        // l = 1
        // r = 10
        // w = 5
        while (l <= r) {
            int cap = l + (r - l) / 2;
            int currentLoad = 0;
            int daysNeeded = 1;
            for (int weight : weights) {
                if (currentLoad + weight > cap) {
                    daysNeeded++;
                    currentLoad = 0;
                }
                currentLoad += weight;
            }

            if (daysNeeded <= days) {
                res = cap;
                r = cap - 1;
            } else {
                l = cap + 1;
            }
        }

        return res;
    }
};
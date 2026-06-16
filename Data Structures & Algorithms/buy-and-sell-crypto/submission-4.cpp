class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        
        int profit = 0;
        for (int r = 0; r < prices.size(); r++)
        {
            if (prices[l] > prices[r])
            {
                l = r;
            }
            int currP = prices[r] - prices[l];

            profit = max(profit, currP);
        }

        return profit;
    }
};

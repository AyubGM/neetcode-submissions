class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int left = 0;
        int right = 1;
        int maxProfit = 0;

       while (right < prices.size())
       {
        if (prices[left] < prices[right])
        {
            const int currProfit = prices[right] - prices[left];
            maxProfit = std::max(maxProfit, currProfit);
        }
        else
        {
            left = right;
        }
        right++;
       }
        return maxProfit;
    }
};

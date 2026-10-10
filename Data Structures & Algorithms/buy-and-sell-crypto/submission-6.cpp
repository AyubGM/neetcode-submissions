class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t l{};
        int mProfit = 0;
        for (size_t r{1}; r < prices.size(); r++)
        {
            if (prices[l] < prices[r])
            {
                mProfit = std::max(mProfit,prices[r] - prices[l]);
            } else
            {
                l = r;
            }
        }

        return mProfit;

    }
};

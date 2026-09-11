class Solution {
public:

    int fun(vector<int>& prices, int i, int buy,
            vector<vector<int>>& dp)
    {
        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        if(buy == 1)
        {
            // Buy
            int take = -prices[i] + fun(prices, i+1, 0, dp);

            // Skip
            int notTake = fun(prices, i+1, 1, dp);

            return dp[i][buy] = max(take, notTake);
        }
        else
        {
            // Sell
            int sell = prices[i] + fun(prices, i+1, 1, dp);

            // Skip
            int notSell = fun(prices, i+1, 0, dp);

            return dp[i][buy] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return fun(prices, 0, 1, dp);
    }
};
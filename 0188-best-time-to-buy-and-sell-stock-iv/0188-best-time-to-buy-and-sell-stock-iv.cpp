class Solution {
public:

    int fun(vector<int>& prices, int i, int buy, int cap,
            vector<vector<vector<int>>>& dp)
    {
        // Saare days khatam ya transactions khatam
        if(i == prices.size() || cap == 0)
            return 0;

        // Already calculated
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if(buy == 1)
        {
            // Stock BUY karo
            int take = -prices[i] +
                       fun(prices, i+1, 0, cap, dp);

            // Stock BUY mat karo
            int skip = fun(prices, i+1, 1, cap, dp);

            return dp[i][buy][cap] = max(take, skip);
        }
        else
        {
            // Stock SELL karo
            int sell = prices[i] +
                       fun(prices, i+1, 1, cap-1, dp);

            // SELL mat karo
            int skip = fun(prices, i+1, 0, cap, dp);

            return dp[i][buy][cap] = max(sell, skip);
        }
    }

    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k+1, -1))
        );

        return fun(prices, 0, 1, k, dp);
    }
};
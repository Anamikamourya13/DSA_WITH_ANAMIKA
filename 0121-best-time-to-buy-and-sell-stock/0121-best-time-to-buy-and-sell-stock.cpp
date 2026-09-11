class Solution {
public:

    int fun(vector<int>& prices, int i, int minPrice,
            vector<int>& dp)
    {
        // Base case
        if(i == prices.size())
            return 0;

        // Already calculated
        if(dp[i] != -1)
            return dp[i];

        // Minimum buying price
        minPrice = min(minPrice, prices[i]);

        // Aaj sell karne ka profit
        int profit = prices[i] - minPrice;

        // Aage ke days check karo
        int skip = fun(prices, i+1, minPrice, dp);

        // Maximum answer store karo
        return dp[i] = max(profit, skip);
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<int> dp(n, -1);

        return fun(prices, 0, prices[0], dp);
    }
};
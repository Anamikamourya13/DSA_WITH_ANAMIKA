class Solution {
public:

    int fun(vector<int>& prices, int i, int buy,int cap,
            vector<vector<vector<int>>>& dp)
    {
        // Saare din khatam
        // ya transactions khatam
        if(i == prices.size() || cap == 0)
            return 0;
        
        // Pehle se answer nikala hua hai
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if(buy == 1)
        {
            // Buy
            int take = -prices[i] + fun(prices, i+1, 0,cap, dp);

            // Skip
            int notTake = fun(prices, i+1, 1,cap, dp);

            return dp[i][buy][cap]= max(take, notTake);
        }
        else
        {
            // Sell
            int sell = prices[i] + fun(prices, i+1, 1,cap-1, dp);

            // Skip
            int notSell = fun(prices, i+1, 0,cap, dp);

            return dp[i][buy][cap] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

         vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return fun(prices, 0, 1,2, dp);
    }
};
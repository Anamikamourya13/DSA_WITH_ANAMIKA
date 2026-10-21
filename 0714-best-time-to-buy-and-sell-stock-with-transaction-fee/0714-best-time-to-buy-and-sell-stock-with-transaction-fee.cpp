
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int prevCash = cash;
            int prevHold = hold;

            // Sell today or keep no stock
            cash = max(prevCash, prevHold + prices[i] - fee);

            // Buy today or keep holding
            hold = max(prevHold, prevCash - prices[i]);
        }

        return cash;
    }
};

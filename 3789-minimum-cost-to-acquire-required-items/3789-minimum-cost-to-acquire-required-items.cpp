
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long mn = min(need1, need2);
        long long mx = max(need1, need2);

        // Case 1: Buy separate items
        long long ans1 = 1LL * need1 * cost1
                       + 1LL * need2 * cost2;

        // Case 2: Buy common items + remaining separate items
        long long ans2 = mn * costBoth
                       + (need1 - mn) * cost1
                       + (need2 - mn) * cost2;

        // Case 3: Buy only combined items
        long long ans3 = mx * costBoth;

        return min({ans1, ans2, ans3});
    }
};

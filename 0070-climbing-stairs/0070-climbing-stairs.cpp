class Solution {
public:
    unordered_map<int,int> dp;

    int climbStairs(int n, int i) {

        // Base case
        if (i == n)
            return 1;

        if (i > n)
            return 0;

        // Already calculated
        if (dp.find(i) != dp.end())
            return dp[i];

        // Take 1 step OR 2 steps
        return dp[i] = climbStairs(n, i + 1)
                     + climbStairs(n, i + 2);
    }

    int climbStairs(int n) {
        return climbStairs(n, 0);
    }
};
class Solution {
public:

    int fun(string &text1, string &text2,
            int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if(i == text1.size() || j == text2.size())
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters same
        if(text1[i] == text2[j])
        {
            return dp[i][j] =
                1 + fun(text1, text2, i+1, j+1, dp);
        }

        // Characters different
        return dp[i][j] = max(
            fun(text1, text2, i+1, j, dp),
            fun(text1, text2, i, j+1, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return fun(text1, text2, 0, 0, dp);
    }
};
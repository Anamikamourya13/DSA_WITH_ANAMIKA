
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Empty string ko convert karne ke base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;  // Delete all characters
        }

        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;  // Insert all characters
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    // Same character: no new operation
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Choose the minimum of insert, delete, replace
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],
                        dp[i - 1][j],
                        dp[i - 1][j - 1]
                    });
                }
            }
        }

        return dp[m][n];
    }
};



#include <vector>
#include <numeric>

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Corner cases
        // If k == 0, Alice starts with 0 points and stops immediately. Probability is 1.
        // If n >= k + maxPts - 1, Alice can never exceed n even with the maximum possible last draw.
        if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }

        // dp[i] stores the probability of reaching exactly 'i' points
        std::vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0; // Base case: 100% probability to start at 0 points

        double windowSum = 1.0; // Keeps track of the sum of probabilities in the sliding window
        double finalProbability = 0.0;

        for (int i = 1; i <= n; ++i) {
            // The probability to get i points is the sum of the last 'maxPts' probabilities divided by maxPts
            dp[i] = windowSum / maxPts;

            // If the game continues (score is less than k), add the current probability to the window
            if (i < k) {
                windowSum += dp[i];
            } else {
                // If the game has stopped (score is >= k), accumulate this final score into our result
                finalProbability += dp[i];
            }

            // Maintain the sliding window size of 'maxPts'
            // When the index moves past maxPts, remove the oldest element from windowSum
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return finalProbability;
    }
};

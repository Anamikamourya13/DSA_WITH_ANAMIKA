class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Step 1: First window ka sum
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        // Step 2: Initial maximum
        int maxSum = windowSum;

        // Step 3: Slide the window
        for (int i = k; i < nums.size(); i++) {

            // Remove left element
            windowSum -= nums[i - k];

            // Add new right element
            windowSum += nums[i];

            // Update maximum
            maxSum = max(maxSum, windowSum);
        }

        // Step 4: Return maximum average
        return (double)maxSum / k;
    }
};
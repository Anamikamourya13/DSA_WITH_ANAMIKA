class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> ans(n, -1);

        int windowSize = 2 * k + 1;

        if (windowSize > n)
            return ans;

        long long sum = 0;

        // First window
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }

        int center = k;
        ans[center] = sum / windowSize;

        // Slide the window
        for (int i = windowSize; i < n; i++) {

            sum -= nums[i - windowSize];

            sum += nums[i];

            center++;

            ans[center] = sum / windowSize;
        }

        return ans;
    }
};
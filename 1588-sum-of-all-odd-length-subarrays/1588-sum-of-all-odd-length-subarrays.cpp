class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();

        // Prefix Sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int ans = 0;

        // Start index
        for (int i = 0; i < n; i++) {

            // End index
            // +2 means length will remain odd
            for (int j = i; j < n; j += 2) {

                int sum = prefix[j + 1] - prefix[i];

                ans += sum;
            }
        }

        return ans;
    }
};

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // Pair each nums2 value with its corresponding nums1 value
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums2[i], nums1[i]});
        }

        // Sort by nums2 in descending order
        sort(arr.rbegin(), arr.rend());

        // Min heap keeps the largest k nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0;
        long long ans = 0;

        for (auto& p : arr) {
            int num2 = p.first;
            int num1 = p.second;

            // Add current nums1 value
            pq.push(num1);
            sum += num1;

            // Remove the smallest if we selected more than k
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            // Exactly k elements: calculate the score
            if (pq.size() == k) {
                ans = max(ans, sum * num2);
            }
        }

        return ans;
    }
};

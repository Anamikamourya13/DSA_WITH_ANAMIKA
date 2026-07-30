class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        vector<int> ans(n);

        if (k == 0)
            return vector<int>(n, 0);

        for (int i = 0; i < n; i++) {

            int sum = 0;

            if (k > 0) {

                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }

            } else {

                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }

            }

            ans[i] = sum;
        }

        return ans;
    }
};
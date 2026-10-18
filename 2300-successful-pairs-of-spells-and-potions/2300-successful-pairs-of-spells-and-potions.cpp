
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                               vector<int>& potions,
                               long long success) {

        sort(potions.begin(), potions.end());

        int n = spells.size();
        int m = potions.size();

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int low = 0;
            int high = m - 1;
            int first = m;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                long long product = 1LL * spells[i] * potions[mid];

                if (product >= success) {
                    first = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            ans[i] = m - first;
        }

        return ans;
    }
};

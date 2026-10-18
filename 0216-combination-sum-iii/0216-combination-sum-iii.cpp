
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int start, int k, int n) {
        // Base case
        if (path.size() == k && n == 0) {
            ans.push_back(path);
            return;
        }

        // Invalid condition
        if (path.size() == k || n <= 0) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            path.push_back(i);

            solve(i + 1, k, n - i);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1, k, n);
        return ans;
    }
};

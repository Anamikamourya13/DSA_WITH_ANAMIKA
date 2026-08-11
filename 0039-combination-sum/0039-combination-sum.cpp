class Solution {
public:
    void fun(vector<int>& a, int n, int index,
             vector<int>& temp, int sum,
             vector<vector<int>>& res, int target) {

        // Base case
        if (index == n) {
            if (sum == target) {
                res.push_back(temp);
            }
            return;
        }

        // 1. Don't take current element
        fun(a, n, index + 1, temp, sum, res, target);

        // 2. Take current element
        if (sum + a[index] <= target) {

            temp.push_back(a[index]);
            sum += a[index];

            // index same because element can be reused
            fun(a, n, index, temp, sum, res, target);

            // Backtracking
            sum -= a[index];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        fun(candidates, candidates.size(), 0,
            temp, 0, res, target);

        return res;
    }
};
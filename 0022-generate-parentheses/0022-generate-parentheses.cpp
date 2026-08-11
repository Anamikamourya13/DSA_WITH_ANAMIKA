class Solution {
public:

    void fun(int open, int close, int n, string &tmp, vector<string> &result) {

        // Base case
        if (open == n && close == n) {
            result.push_back(tmp);
            return;
        }

        // Add '('
        if (open < n) {
            tmp.push_back('(');
            fun(open + 1, close, n, tmp, result);
            tmp.pop_back();
        }

        // Add ')'
        if (close < open) {
            tmp.push_back(')');
            fun(open, close + 1, n, tmp, result);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string tmp = "";

        fun(0, 0, n, tmp, result);

        return result;
    }
};
class Solution {
public:

    bool isPalindrome(string &s, int start, int end) {

        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    void solve(string &s, int index,
               vector<string>& temp,
               vector<vector<string>>& ans) {

        // complete string partitioned
        if (index == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {

            // check s[index...i] is palindrome
            if (isPalindrome(s, index, i)) {

                // choose
                temp.push_back(s.substr(index, i - index + 1));

                // explore
                solve(s, i + 1, temp, ans);

                // backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, 0, temp, ans);

        return ans;
    }
};
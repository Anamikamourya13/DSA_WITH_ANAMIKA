class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        vector<int> pos;

        // Store positions of all 1s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }

        // Not enough 1s
        if (pos.size() < k) {
            return "";
        }

        string ans = "";

        // Check every group of k consecutive 1s
        for (int i = 0; i + k - 1 < pos.size(); i++) {

            int start = pos[i];
            int end = pos[i + k - 1];

            string curr = s.substr(start, end - start + 1);

            if (ans == "" ||
                curr.size() < ans.size() ||
                (curr.size() == ans.size() && curr < ans)) {

                ans = curr;
            }
        }

        return ans;
    }
};
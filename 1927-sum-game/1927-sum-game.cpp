class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum = 0;
        int cnt = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                cnt--;
            } else {
                sum += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                cnt++;
            } else {
                sum -= num[i] - '0';
            }
        }

        return 2 * sum != 9 * cnt;
    }
};
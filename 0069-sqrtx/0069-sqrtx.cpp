class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return 0;

        int left = 1;
        int right = x;
        int ans = 0;

        while (left <= right) {

            long long mid = left + (right - left) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                ans = mid;          // Store current valid answer
                left = mid + 1;     // Try to find a bigger valid answer
            }
            else {
                right = mid - 1;    // Square is too large
            }
        }

        return ans;
    }
};
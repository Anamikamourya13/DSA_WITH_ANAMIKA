class Solution {
public:

    long long fn(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + (long long)speed - 1) / speed;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = fn(piles, mid);

            if (hours > h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
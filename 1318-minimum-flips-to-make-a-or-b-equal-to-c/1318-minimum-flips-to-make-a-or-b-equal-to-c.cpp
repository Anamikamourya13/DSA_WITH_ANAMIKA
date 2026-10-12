
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;

        while (a > 0 || b > 0 || c > 0) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;

            if (bitC == 1) {
                // At least one of a or b must be 1
                if (bitA == 0 && bitB == 0)
                    flips++;
            } else {
                // Both bits must be 0
                flips += bitA + bitB;
            }

            // Move to the next binary bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};
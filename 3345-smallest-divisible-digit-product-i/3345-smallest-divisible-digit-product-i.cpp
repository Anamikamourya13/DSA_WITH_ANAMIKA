#include <string>

class Solution {
private:
    // Helper function to calculate the product of digits
    int getDigitProduct(int num) {
        int prod = 1;
        while (num > 0) {
            prod *= (num % 10);
            num /= 10;
        }
        return prod;
    }

public:
    int smallestNumber(int n, int t) {
        int current = n;
        while (true) {
            if (getDigitProduct(current) % t == 0) {
                return current;
            }
            current++;
        }
    }
};

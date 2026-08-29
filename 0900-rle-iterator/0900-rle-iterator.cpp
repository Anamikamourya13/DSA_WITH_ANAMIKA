class RLEIterator {
public:
    vector<int> encoded;
    int index;

    RLEIterator(vector<int>& encoding) {
        encoded = encoding;
        index = 0;
    }

    int next(int n) {

        while (index < encoded.size()) {

            // Current value has enough elements
            if (encoded[index] >= n) {

                encoded[index] -= n;

                return encoded[index + 1];
            }

            // Current group is not enough
            n -= encoded[index];

            // Move to next [count, value] pair
            index += 2;
        }

        return -1;
    }
};
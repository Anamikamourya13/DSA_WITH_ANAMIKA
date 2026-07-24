class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int altitude = 0;
        int maximum = 0;

        for (int i = 0; i < gain.size(); i++) {

            altitude += gain[i];

            maximum = max(maximum, altitude);
        }

        return maximum;
    }
};
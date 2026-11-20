
class Solution {
public:
    bool isSelfCrossing(vector<int>& d) {
        
        for (int i = 3; i < d.size(); i++) {

            // Case 1: Current line crosses 3 steps back
            if (d[i] >= d[i-2] &&
                d[i-1] <= d[i-3]) {
                return true;
            }

            // Case 2: Current line overlaps 4 steps back
            if (i >= 4 &&
                d[i-1] == d[i-3] &&
                d[i] + d[i-4] >= d[i-2]) {
                return true;
            }

            // Case 3: Current line crosses 5 steps back
            if (i >= 5 &&
                d[i-2] >= d[i-4] &&
                d[i] + d[i-4] >= d[i-2] &&
                d[i-1] <= d[i-3] &&
                d[i-1] + d[i-5] >= d[i-3]) {
                return true;
            }
        }

        return false;
    }
};

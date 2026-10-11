
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort balloons by starting point
        sort(points.begin(), points.end());

        int arrows = 1;
        long long end = points[0][1];

        for (int i = 1; i < points.size(); i++) {
            // Overlapping balloons: narrow the common interval
            if (points[i][0] <= end) {
                end = min(end, (long long)points[i][1]);
            }
            else {
                // No overlap: shoot a new arrow
                arrows++;
                end = points[i][1];
            }
        }

        return arrows;
    }
};
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        // Traverse every row
        for (int i = 0; i < rows; i++) {

            int left = 0;
            int right = cols - 1;

            // Assume no negative number exists in this row
            int ans = cols;

            while (left <= right) {

                int mid = left + (right - left) / 2;

                // Negative found
                if (grid[i][mid] < 0) {

                    ans = mid;          // Store possible first negative
                    right = mid - 1;    // Search more on left
                }

                // Positive or Zero
                else {

                    left = mid + 1;     // Search on right
                }
            }

            // Add negatives of current row
            count += (cols - ans);
        }

        return count;
    }
};
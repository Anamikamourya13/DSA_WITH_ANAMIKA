class Solution {
public:

    // 4 directions: up, down, left, right
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    // Check whether the cell is inside the grid
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Queue stores positions of rotten oranges
        queue<pair<int, int>> q;

        int fresh = 0;
        int time = 0;

        // Find rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // If orange is already rotten
                if (grid[i][j] == 2) {
                    q.push({i, j});

                    // Mark as visited
                    grid[i][j] = -2;
                }

                // Count fresh oranges
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // BFS: rotten oranges spread to fresh oranges
        while (!q.empty() && fresh > 0) {

            // One BFS level = one minute
            time++;

            int s = q.size();

            // Process all oranges of current level
            while (s--) {

                pair<int, int> p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                // Check all 4 directions
                for (int k = 0; k < 4; k++) {

                    int row = r + x[k];
                    int col = c + y[k];

                    // If valid cell and fresh orange
                    if (valid(row, col, n, m) &&
                        grid[row][col] == 1) {

                        // Add newly rotten orange to queue
                        q.push({row, col});

                        // Mark it as visited
                        grid[row][col] = -2;

                        // Decrease fresh orange count
                        fresh--;
                    }
                }
            }
        }

        // If fresh oranges are still remaining
        if (fresh > 0)
            return -1;

        return time;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start or destination blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 possible directions
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<tuple<int, int, int>> q;

        // row, col, distance
        q.push({0, 0, 1});

        // Mark starting cell visited
        grid[0][0] = 1;

        while (!q.empty()) {

            auto [r, c, dist] = q.front();
            q.pop();

            // Destination reached
            if (r == n-1 && c == n-1)
                return dist;

            // Explore all 8 directions
            for (int i = 0; i < 8; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                // Check valid and unvisited cell
                if (nr >= 0 && nc >= 0 &&
                    nr < n && nc < n &&
                    grid[nr][nc] == 0) {

                    q.push({nr, nc, dist + 1});

                    // Mark visited
                    grid[nr][nc] = 1;
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    int x[4] = {-1, 1, 0, 0};//for directions
    int y[4] = {0, 0, -1, 1};

    //check current cell is inside the grid
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    //dfs poori connected island ko visit krna
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j,
             vector<vector<bool>>& vis) {

        vis[i][j] = 1; //current cell ko visited mark 

//4 direction mein check kro
        for (int k = 0; k < 4; k++) {

            int row = i + x[k];
            int col = j + y[k];
            
 //if valid cell h , land h, unvis h to dfs ko call kro
            if (valid(row, col, n, m) &&
                grid[row][col] == '1' &&
                vis[row][col] == 0) {

                dfs(grid, n, m, row, col, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int res = 0; //islands count

        vector<vector<bool>> vis(n); //visited array form

        for (int i = 0; i < n; i++) {
            vector<bool> t(m, 0);
            vis[i] = t;
        }
 
 //hr cell ko traverse kro
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

            //new islands
                if (grid[i][j] == '1' && vis[i][j] == 0) {

                    dfs(grid, n, m, i, j, vis);//connected  cell visit   kro

                    res++;
                }
            }
        }

        return res;
    }
};
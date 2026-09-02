class Solution {
public:
    int n, m;
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int i, int j) {
        
        // Out of boundary or not O
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;

        // Mark this O as safe
        board[i][j] = '#';

        // Visit 4 directions
        for(int k = 0; k < 4; k++) {
            dfs(board, i + dx[k], j + dy[k]);
        }
    }

    void solve(vector<vector<char>>& board) {
        
        if(board.empty())
            return;

        n = board.size();
        m = board[0].size();

        // Step 1: Boundary O ko safe mark karo

        for(int i = 0; i < n; i++) {
            dfs(board, i, 0);       // Left boundary
            dfs(board, i, m - 1);   // Right boundary
        }

        for(int j = 0; j < m; j++) {
            dfs(board, 0, j);       // Top boundary
            dfs(board, n - 1, j);   // Bottom boundary
        }

        // Step 2: Remaining O are surrounded -> X
        // Safe # ko wapas O

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O')
                    board[i][j] = 'X';

                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

class Solution {
public:
    int ans = 0;
    void solve(int row , int n , vector<int>& col, vector<int>& diag1, vector<int>& diag2){
        // all queens successfully placed
        if(row == n){
            ans++;
            return;
        } 

        for(int c =0; c<n; c++){
            int d1 = row -  c + n - 1;
            int d2 = row + c;

            //check queen can be placed safely
             if(col[c] || diag1[d1] || diag2[d2])
              continue;
             // Place queen
            col[c] = 1;
            diag1[d1] = 1;
            diag2[d2] = 1;

            solve(row + 1, n, col, diag1, diag2);

            // Undo placement (Backtracking)
            col[c] = 0;
            diag1[d1] = 0;
            diag2[d2] = 0;

        }
    }
    int totalNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> diag1(2*n - 1, 0);
        vector<int> diag2(2*n - 1, 0);

        solve(0, n, col, diag1, diag2);

        return ans;
    }
};
class Solution {
public:
    vector<vector<string>>ans;

    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        //same col
        for(int i=0; i<row; i++)
        {
            if(board[i][col]=='Q')
             return false;
        }
        //upper-left diagonal

        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
        {
            if(board[i][j]=='Q')
             return false;
        }
        //upper-right diagonal

       for(int i = row - 1, j = col + 1;
            i >= 0 && j < n;
            i--, j++)
        {
            if(board[i][j]=='Q')
             return false;
        }
        return true;
    }
    void solve(vector<string> &board,int row,int n)
    {
        //all  row complete
        if(row==n)
        {
            ans.push_back(board);
             return;
        }
        //try safe place
        for(int col =0;col<n;col++)
        {
            //check safe place
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';
                solve(board,row+1,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(board,0,n);
        return ans;
    }
};
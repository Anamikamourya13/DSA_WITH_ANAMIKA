class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size();
        int m = a[0].size();
        int row = n-1;
        int col= 0;
        while(row>=0 && col < m){
            if(a[row][col]==target)
            return true;
            if(a[row][col]>target)
            row--;
            else
            col++;
        }
        return false;
        
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int cols = matrix[0].size();

        vector<int> ans;

        int top = 0;
        int bottom =  row - 1;
        int left  = 0;
        int right  =  cols -1;

      while(top<= bottom && left <= right){
        for(int i =  left; i<= right; i++)
         ans.push_back(matrix[top][i]);
         top++;

         for(int j = top; j<= bottom ; j++)
         ans.push_back(matrix[j][right]);
         right--;

         if(top<= bottom){
            for(int i = right; i>= left; i--)
            ans.push_back(matrix[bottom][i]);
            bottom--;
         }
         if(left <= right){
            for(int j = bottom; j>= top;  j--)
            ans.push_back(matrix[j][left]);
            left++;
         }

    }
    return ans;

    }
};
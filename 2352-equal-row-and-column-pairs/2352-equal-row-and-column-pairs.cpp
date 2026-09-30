class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       int n = grid.size();
       int ans = 0;

       map<vector<int>,int> mp;

       //store all rows
       for(int i=0; i<n;i++){
        mp[grid[i]]++;
       } 

       //check every column
       for(int j=0; j<n; j++){
        vector<int>col;
        
        for(int i=0; i<n; i++){
            col.push_back(grid[i][j]);
        }
        if(mp.find(col) != mp.end()){
            ans += mp[col];
        }

       }
       return ans;
    }
};
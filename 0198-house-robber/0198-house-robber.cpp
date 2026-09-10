class Solution {
public:
       vector<vector<int>>dp;
       int fun(vector<int> &a,int n ,int i,  int free)
       {
        if(i==n)
         return 0;

        if(dp[i][free] != -1)
         return dp[i][free];

         if(free==0)
          return dp[i][free]=fun(a,n,i+1,1);

          int c1= a[i]+fun(a,n,i+1,0);
          int c2=fun(a,n,i+1,1);

          return dp[i][free]=max(c1,c2);
       }

    int rob(vector<int>&a) {
        int n =a.size();
        dp.resize(n, vector<int>(2,-1));
         return fun(a,n,0,1);
        }
};
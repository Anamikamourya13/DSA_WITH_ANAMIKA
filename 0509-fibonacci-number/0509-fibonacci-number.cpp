class Solution {
public:
    unordered_map<int,int>dp;   //hashmap

    int fib(int n) {
        if (n==0)
        return 0;

         if(n==1)
         return 1;
         
         if(dp.find(n) != dp.end()) //already calculated
           return dp[n];

         dp[n] = fib(n - 1) + fib(n - 2); //shortly answer
          return dp[n];
    }
};
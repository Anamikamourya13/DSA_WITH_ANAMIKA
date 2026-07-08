class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero =  0;
        int one=0;
        int res = 0;
        unordered_map<int,int>f;
        f[0]=-1;
        for( int i=0;i<n; i++)
        {
            if(nums[i]==0)
             zero ++;
            else
              one++;
            int diff = zero - one;
              if(diff==0)
              {
                res=max(res,i+1);
                continue;
               }
               if(f.find(diff)==f.end())
               {
                f[diff]=i;
               }
               else{
                int index = f[diff];
                int length = i-index;
                res = max(length, res);
               }
        }
        return res;
    }
};
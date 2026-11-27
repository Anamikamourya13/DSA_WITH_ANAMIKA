class Solution {
public:
    int solve(vector<int>& nums, int start ,int end){
        int prev2 =0;
        int prev1=0;

        for(int i= start; i<= end;i++){
            int take = nums[i]+prev2;
            int skip=prev1;
            int curr = max(take, skip);

            prev2 = prev1;
            prev1=curr;

        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
         return nums[0];

         //case1 last house ignore
         int case1= solve(nums,0,n-2);

         //case2 first house ignore

         int case2= solve(nums,1,n-1);

         return max(case1,case2);
        
    }
};
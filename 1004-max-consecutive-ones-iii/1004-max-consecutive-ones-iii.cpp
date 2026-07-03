class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int result=0;
        int zerocount = 0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r]==0)
             zerocount++;
            while(zerocount > k)
            {
                if(nums[l] ==0)
                  zerocount--;
                  l++;
            }
            result = max(result, r-l+1);
        } 
        return result;
    }
};
class Solution {
public:
    int find(vector<int>& nums, int x,bool first) {
        int n = nums.size();
        int low= 0;
        int high = n-1;
        int res = -1;

        while(low<=high){
            int guess=(low+high)/2;

            if(nums[guess] < x){
                low = guess + 1;
            }else if(nums[guess] > x){
                high = guess -1;
            }else{
                res = guess;
               if(first)
                high = guess-1;
               else
                low = guess +1;
            }
        }
        return res;
    }
        vector<int> searchRange(vector<int>& nums, int target) {
        return {find(nums, target, true), find(nums, target, false)};
    }
};
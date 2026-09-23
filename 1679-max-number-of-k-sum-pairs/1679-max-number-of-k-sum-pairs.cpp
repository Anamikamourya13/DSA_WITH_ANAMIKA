class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0;
    int right =  n-1;
    int count =0;
    sort(nums.begin(),nums.end());
     
    while(left < right){
        int sum = nums[left] + nums[right];

        if(sum ==k){
            count++;
            left++;
            right--;
        }
        else if (sum < k){
            left++;
        }
        else{ 
          right--;
        }
    }
    return count;
    }
};
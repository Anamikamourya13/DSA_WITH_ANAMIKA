/*class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high = n-1;
        while(low < high){
            int mid = (low+high)/2;
            if(nums[mid] > nums[high]){
                low = mid+1;
            }else{
                high =mid;
            }
        }
        return nums[low];
    }
};*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int res = n - 1;   // Last index ko initial answer maan lo

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[n - 1]) {
                // Minimum right side me hai
                low = mid + 1;
            }
            else {
                // Ye minimum ho sakta hai
                res = mid;
                high = mid - 1;
            }
        }

        return nums[res];
    }
};
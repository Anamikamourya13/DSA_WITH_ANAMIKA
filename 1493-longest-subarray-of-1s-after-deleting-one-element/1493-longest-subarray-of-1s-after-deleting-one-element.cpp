class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int zero = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0) {
                zero++;
            }

            // Window me maximum 1 zero hona chahiye
            while (zero > 1) {
                if (nums[left] == 0) {
                    zero--;
                }
                left++;
            }

            // Ek element delete karna compulsory hai
            ans = max(ans, right - left);
        }

        return ans;
    }
};
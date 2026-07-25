class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        // Step 1: Make a copy
        vector<int> copy = nums;

        // Step 2: Sort the copy
        sort(copy.begin(), copy.end());

        int start = -1;
        int end = -1;

        // Step 3: Find first mismatch from left
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != copy[i]) {
                start = i;
                break;
            }
        }

        // Step 4: If already sorted
        if (start == -1)
            return 0;

        // Step 5: Find first mismatch from right
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != copy[i]) {
                end = i;
                break;
            }
        }

        // Step 6: Return length
        return end - start + 1;
    }
};
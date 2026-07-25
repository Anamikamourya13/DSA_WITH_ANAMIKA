class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix first element
        for (int i = 0; i < n - 3; i++) {

            // Skip duplicate for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Step 3: Fix second element
            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicate for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Step 4: Two pointers
                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if (sum == target) {

                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]}
                        );

                        left++;
                        right--;

                        // Skip duplicate from left
                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        // Skip duplicate from right
                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }

                    else if (sum < target) {
                        left++;
                    }

                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
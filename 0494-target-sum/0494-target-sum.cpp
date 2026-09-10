class Solution {
public:

    int fun(vector<int>& nums, int target, int i, int sum)
    {
        if(i == nums.size())
        {
            if(sum == target)
                return 1;

            return 0;
        }

        int plus = fun(nums, target, i+1, sum + nums[i]);

        int minus = fun(nums, target, i+1, sum - nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        return fun(nums, target, 0, 0);
    }
};
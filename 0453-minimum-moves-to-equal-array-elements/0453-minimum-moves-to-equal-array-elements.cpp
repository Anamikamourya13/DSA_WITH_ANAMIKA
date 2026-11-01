class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long sum = 0;
        int minm = INT_MAX;
        int n = nums.size();
        
        for (int num : nums) {
            sum += num;
            minm = min(minm, num);
        }
        
        return sum - (long long)minm * n;
    }
};

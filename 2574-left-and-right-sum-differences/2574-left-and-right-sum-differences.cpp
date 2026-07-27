class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer(nums.size());
        int totalsum=0;
        for(int i=0; i<nums.size();i++){
            totalsum += nums[i];
        } 
        int leftsum=0;
        for(int i=0; i<nums.size();i++){
            int rightsum = totalsum - nums[i]- leftsum;
            answer[i] = abs(leftsum - rightsum);
             leftsum += nums[i];
        }
        return answer;
    }
};
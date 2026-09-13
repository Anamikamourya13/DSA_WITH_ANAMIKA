class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    int x = k;

  while(find(nums.begin(), nums.end(), x) != nums.end())
    {
        x += k;
    }
    return x;
    }
};
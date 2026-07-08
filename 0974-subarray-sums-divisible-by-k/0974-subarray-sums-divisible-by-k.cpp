class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> f;
    f[0]=1;
    int ans =0;
    int sum=0;
    int n= nums.size();
    for(int i=0;  i<n;i++){
        sum+=nums[i];
        int rem =sum%k;
        if(rem<0)
            rem = rem+k;
        ans += f[rem];
        f[rem]++;
    }
        return ans;
    }
};
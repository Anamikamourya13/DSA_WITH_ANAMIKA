class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i =0; i<nums.size();  i++){
            if(mp.find(nums[i])!=mp.end()){
               int differnce = i-mp[nums[i]];
                if(differnce<=k){
                return true;
            }
         }
         mp[nums[i]]=i;
        }
        return false;
    }
 
};
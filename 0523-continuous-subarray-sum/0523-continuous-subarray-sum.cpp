class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = -1;

        int prefixsum = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefixsum += nums[i];

            int remainder = prefixsum % k;

            if(mp.find(remainder) != mp.end()) {

                int length = i - mp[remainder];

                if(length >= 2) {
                    return true;
                }

            }
            else {

                mp[remainder] = i;

            }
        }

        return false;
    }
};
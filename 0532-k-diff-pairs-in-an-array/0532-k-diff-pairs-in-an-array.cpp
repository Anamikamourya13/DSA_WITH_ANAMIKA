class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        
        int ans = 0;
        
        for(const int& num : nums){
            if(counter.find(num) == counter.end()){
                if(counter.find(num-k) != counter.end()) ++ans;
                if(counter.find(num+k) != counter.end()) ++ans;
            }else if(counter[num] == 1){
                if(k == 0) ++ans;
            }
            ++counter[num];
        }
      return ans;
    }
};
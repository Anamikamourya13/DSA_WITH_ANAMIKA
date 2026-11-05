class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int ans = 0;

        for(int i = 0; i < arr1.size(); i++) {

            bool valid = true;

            for(int j = 0; j < arr2.size(); j++) {

                // Check absolute difference
                if(abs(arr1[i] - arr2[j]) <= d) {
                    valid = false;
                    break;
                }
            }

            // Count only valid elements
            if(valid) {
                ans++;
            }
        }

        return ans;
    }
};
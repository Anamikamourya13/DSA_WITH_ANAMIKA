class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1;
        unordered_set<int> result;

        // nums1 ke elements set1 mein daalo
        for (int x : nums1) {
            set1.insert(x);
        }

        // nums2 ke common elements find karo
        for (int x : nums2) {
            if (set1.count(x)) {
                result.insert(x);
            }
        }

        // set ko vector mein convert karo
        return vector<int>(result.begin(), result.end());
    }
};
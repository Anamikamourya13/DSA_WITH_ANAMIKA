class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    set<int> set1(nums1.begin(),nums1.end());//convert in set 
    set<int>set2(nums2.begin(),nums2.end());

    vector<int>answer1; // for answer storing
    vector<int>answer2;

    for(int x : set1){
        if(set2.find(x) == set2.end()){ // to find the element in set2
            answer1.push_back(x);
        }
    }
    for(int x :set2){
        if(set1.find(x)==set1.end()){
            answer2.push_back(x);
        }
    }
    return{answer1,answer2};//return ans
    } 
};

class Solution {
public:
    TreeNode* build(vector<int>& nums,int left , int right) {
     
     // no element
     if(left > right)
      return nullptr;

    // find mid
      int mid = (left + right)/2;

    TreeNode* root  = new TreeNode(nums[mid]);
     // build left
     root->left = build(nums, left, mid-1);

     // build right
      root-> right = build(nums, mid+1, right);
      return root;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};
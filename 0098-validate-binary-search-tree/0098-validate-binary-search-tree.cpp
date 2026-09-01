
class Solution {
public:
    long long prev  =  LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
        return true;

        if (!isValidBST(root->left))//check left
        return false;

        if(root-> val <= prev) // current val must be greater then previous val
          return false;

          prev = root->val;

          return isValidBST(root->right);//check right
        
    }
};
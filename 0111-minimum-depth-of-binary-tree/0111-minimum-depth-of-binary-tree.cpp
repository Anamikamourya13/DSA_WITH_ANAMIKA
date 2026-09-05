class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
         return 0;

         if(root-> left == nullptr)
          return 1+ minDepth(root->right);

        if(root-> right == nullptr)
         return 1+ minDepth(root-> left);

         int left = minDepth(root -> left);
         int right = minDepth(root-> right);

         return 1 + min(left,right);
    }
};
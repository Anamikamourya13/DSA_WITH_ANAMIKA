
class Solution {
public:
      int ans;
      int  k;

      void inorder(TreeNode* root){
      if(root == NULL)
       return ;
    inorder(root->left);//left
       k--;//current node;
       if(k==0){
         ans= root->val;
          return;
       }
       inorder(root->right); //right
      }
      int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        inorder (root);
        return ans;
    }
};
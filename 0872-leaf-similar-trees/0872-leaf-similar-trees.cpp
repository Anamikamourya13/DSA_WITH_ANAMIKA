class Solution {
public:
     void getLeaves(TreeNode* root, vector<int>& leaves) {

     if(root == nullptr)
      return;

     if(root->left == nullptr && root ->right == nullptr){
      leaves.push_back(root->val);
      return;

     }
      getLeaves(root->left,leaves);
      getLeaves(root->right,leaves);
    

    }
     bool leafSimilar(TreeNode* root1, TreeNode* root2)
     {
        vector<int>leaves1;
        vector<int>leaves2;

        getLeaves(root1, leaves1);
        getLeaves(root2, leaves2);

        return leaves1==leaves2;
     }
};
class Solution {
public:
    int dfs(TreeNode* root, int maxValue) {
    if(root==nullptr)
     return 0;

    int count =0;

    if(root->val >= maxValue) // 3>4 not good  if good count 1 
            count = 1;

     maxValue =max( maxValue, root->val);   //store val 
     count += dfs(root->left, maxValue);  //check left
     count += dfs(root->right, maxValue); //check right

     return count;
    }
    int goodNodes(TreeNode* root){
        return dfs(root, root->val);  //call function
    }
};
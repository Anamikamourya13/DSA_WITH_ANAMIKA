class Solution{
public:
    TreeNode* searchBST(TreeNode* root, int k){
        if(root== nullptr)
        return nullptr;
        if(root-> val == k)
        return root;

        if(k<root->val)
         return searchBST(root->left,k);

         return searchBST(root-> right,k);
    }
};

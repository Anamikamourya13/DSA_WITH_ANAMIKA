class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        //base case
        if(root == nullptr)
         return 0;

        //root chhota h, left me or choti valu hogi
         if(root->val < low)
           return rangeSumBST(root->right, low, high);


        //root bda g , right me or badi val hogi
         if(root->val > high)
           return rangeSumBST(root->left, low, high);


        //root range ke andar h 
         return root->val  + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
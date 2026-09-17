class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;
    void inorder(TreeNode* root)
    {
        if(root == nullptr) //agar node null h to wapas return;
        return;
        
        //inorder rule;
        inorder(root->left);
        
        // Previous node available hai tabhi difference nikalo
        if(prev != -1)
         ans = min(ans, root->val - prev);
        
        //current node ko previous bana do
         prev = root->val;
         inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return ans;
        
    }
};
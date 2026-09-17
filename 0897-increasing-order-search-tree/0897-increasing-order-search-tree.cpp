class Solution {
public:
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* curr = dummy;

    void inorder(TreeNode* root)
    {
        if(root == nullptr) //base case
         return;

        inorder(root->left); //left

        root->left = nullptr;  //current node ka left null 

        curr->right = root; // cuurent node ko previous node ke right se connect karo

        curr = root; //current ko aage badha do

        inorder(root->right); //right
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root); // inorder traversal

        return dummy->right; // dummy ke right se actual tree milega
        
    }
};
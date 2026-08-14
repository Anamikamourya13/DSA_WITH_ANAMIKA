class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
        return  nullptr;

        // Swap left and right
        swap(root-> left , root -> right);

        // Recursively invert left subtree
        invertTree(root -> left);

        // Recursively invert right  subtree
        invertTree(root-> right);

        return root;
    }
};
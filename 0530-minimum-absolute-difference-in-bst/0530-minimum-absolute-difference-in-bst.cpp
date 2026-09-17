class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;

    void inorder(TreeNode* root) {

        // Base case
        if(root == NULL)
            return;

        // Left
        inorder(root->left);

        // Previous value available hai
        if(prev != -1)
            ans = min(ans, root->val - prev);

        // Current value ko previous bana do
        prev = root->val;

        // Right
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {

        // Inorder traversal
        inorder(root);

        return ans;
    }
};
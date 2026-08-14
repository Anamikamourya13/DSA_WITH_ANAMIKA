class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        // Both are NULL
        if (root1 == nullptr && root2 == nullptr)
            return true;

        // One is NULL
        if (root1 == nullptr || root2 == nullptr)
            return false;

        // Values are different
        if (root1->val != root2->val)
            return false;

        // Case 1: No flip
        bool noFlip =
            flipEquiv(root1->left, root2->left) &&
            flipEquiv(root1->right, root2->right);

        // Case 2: Flip
        bool flip =
            flipEquiv(root1->left, root2->right) &&
            flipEquiv(root1->right, root2->left);

        // Either no flip or flip should work
        return noFlip || flip;
    }
};
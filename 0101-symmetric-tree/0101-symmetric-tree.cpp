class Solution {
public:

    bool mirror(TreeNode* p, TreeNode* q) {

        // Both are NULL
        if (p == nullptr && q == nullptr)
            return true;

        // One is NULL
        if (p == nullptr || q == nullptr)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Check mirror positions
        return mirror(p->left, q->right) &&
               mirror(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return mirror(root->left, root->right);
    }
};
 
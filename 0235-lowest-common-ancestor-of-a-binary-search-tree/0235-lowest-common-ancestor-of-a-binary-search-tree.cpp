class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q) {

        while (root != nullptr) {

            // Both are on left side
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }

            // Both are on right side
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }

            // Split point = LCA
            else {
                return root;
            }
        }

        return nullptr;
    }
};
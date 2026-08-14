class Solution {
public:

    int ans = INT_MIN;

    int fun(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int left = max(0, fun(root->left));
        int right = max(0, fun(root->right));

        // Path passing through current node
        ans = max(ans, left + root->val + right);

        // Return one side to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {

        fun(root);

        return ans;
    }
};
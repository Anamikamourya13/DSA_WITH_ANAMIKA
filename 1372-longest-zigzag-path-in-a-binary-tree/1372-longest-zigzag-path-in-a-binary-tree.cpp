class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int left, int right) {

        if(root == nullptr)
            return;

        ans = max(ans, max(left, right));

        // move left → next move must be right
        dfs(root->left, right + 1, 0);

        // move right → next move must be left
        dfs(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode* root) {

        dfs(root, 0, 0);

        return ans;
    }
};
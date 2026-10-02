class Solution {
public:

    int pathSum(TreeNode* root, long long targetSum) {

        if(root == nullptr)
            return 0;

        int count = 0;

        if(root->val == targetSum)
            count = 1;

        // check conditions
        count += pathSum(root->left, targetSum - root->val);
        count += pathSum(root->right, targetSum - root->val);

        return count;
    }

    int countpath(TreeNode* root, long long targetSum) {

        if(root == nullptr)
            return 0;

        // calculate sum
        return pathSum(root, targetSum)
             + countpath(root->left, targetSum)
             + countpath(root->right, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        return countpath(root, targetSum);
    }
};
class Solution {
public:
int diameter = 0;
    int height(TreeNode* root){
    if (root == nullptr)
     return 0;

    int leftHeight = height(root -> left);
    int rightHeight = height (root-> right);

    int currentDiameter = leftHeight + rightHeight;

    diameter = max(diameter, currentDiameter);

    return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height (root);
        return diameter;
    }
};
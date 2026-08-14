/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans =  nullptr;
        int fun(TreeNode* node, TreeNode* p, TreeNode* q){
          if(node == nullptr)
           return 0;

        int left = fun(node-> left, p,q);
        int right = fun(node->right, p,q);

        int self =0;

        if(node ==  p || node == q)
         self =  1;

         int total= left + self+ right;

         if(total == 2 && ans == nullptr)
           ans = node;
         return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root, p, q);
        return ans;
    }
};
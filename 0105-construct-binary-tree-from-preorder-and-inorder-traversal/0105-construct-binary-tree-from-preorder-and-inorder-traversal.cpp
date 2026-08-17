
class Solution {
public:
      int preIndex = 0;

      TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right){

        if(left> right)
         return NULL;// no  element

         int rootValue = preorder[preIndex++];
         TreeNode* root = new TreeNode(rootValue);//preorder ka first element = root
         

        //inorder me root find kro
         int index =   left;
         while(inorder[index]!= rootValue){
            index++;
         }
        //left subtree
        root->left = build(preorder, inorder, left, index-1);
         root->right= build(preorder, inorder, index+1, right);

         return root;
      }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
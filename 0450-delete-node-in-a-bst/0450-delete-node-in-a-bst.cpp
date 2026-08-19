class Solution {
public:
    TreeNode* deleteNode( TreeNode* root ,  int key){
        if(root == nullptr)
          return nullptr;
 //search
        if (key < root-> val) {
        root->left =  deleteNode(root->left, key);
        }
        else if
        (key > root->val){
        root->right = deleteNode(root-> right, key);
        }
        else{
        if( root->left == 0) //0 child, right child only
         return root->right;

        if( root->right == 0)// left child
        return root-> left;
        //two child
        TreeNode* temp =  root-> right;
        while(temp->left!= nullptr){
            temp = temp->left;
        }
       root->val=  temp->val;
       root-> right= deleteNode(root->right, temp->val);
    }
    return root;
    }
};
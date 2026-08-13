class Solution{
 public:
   vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    if(root == nullptr)
       return res;

       queue<TreeNode*> q;
       q.push(root);// root push 
       while(!q.empty()){
        int levelSize = q.size();
        vector<int> temp;//for storing val
        while(levelSize--){
            TreeNode* t = q.front();
            q.pop();
            temp.push_back(t-> val);
            if(t-> left != nullptr)// add left
              q.push(t-> left);
            if(t-> right != nullptr)// add right
            q.push(t->right);
        }
        res.push_back(temp); // add in temp  
       }
       return res; // answer in array form 
   }    
};
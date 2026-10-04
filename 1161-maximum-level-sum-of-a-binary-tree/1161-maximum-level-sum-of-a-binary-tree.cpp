class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       
     queue<TreeNode*>q;
     //level numbering start from 1
     int level =1;

     //max sum initially  very small
     int maxSum = INT_MIN;
     //answer leve;
     int ans =1;
     //bfs starts from root
     q.push(root);

    
     while(!q.empty()){
        //current level ke nodes
      int size=q.size();
      //current level ka sum
      int sum=0;

      for(int i=0; i<size; i++){
        TreeNode* node =q.front();
        q.pop();
        sum += node->val; //current level ka sum

        if(node->left) //next level ka children queue me 
         q.push(node->left);

        if(node->right)
         q.push(node->right);
      }

      //pura level complete hone ke bd maximum check
         if(sum > maxSum){
            maxSum =  sum;
            ans = level;

         }
         level++; //next level;
      } 
      return ans ; 
    }
};
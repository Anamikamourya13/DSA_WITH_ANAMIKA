class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;  //final right side nodes
        queue<TreeNode*> q;//bfs for queue

        if(root == nullptr)
            return ans;

        q.push(root); //root se start 

        while(!q.empty()) {

            int size = q.size();  // current level ka node

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();
 
 //next level ke nodes ko queue me dalo
                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);

//current level ka last node = rightmost
                if(i == size - 1)
                    ans.push_back(node->val);
            }
        }

        return ans;
    }
};
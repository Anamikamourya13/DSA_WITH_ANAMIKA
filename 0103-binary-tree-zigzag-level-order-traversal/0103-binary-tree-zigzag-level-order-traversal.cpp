class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int levelSize = q.size();

            vector<int> temp;

            while (levelSize--) {

                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if (t->left != nullptr)
                    q.push(t->left);

                if (t->right != nullptr)
                    q.push(t->right);
            }

            if (!leftToRight) {
                reverse(temp.begin(), temp.end());
            }

            res.push_back(temp);

            leftToRight = !leftToRight;
        }

        return res;
    }
};
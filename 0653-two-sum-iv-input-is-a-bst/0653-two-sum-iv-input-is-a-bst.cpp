
class Solution {
public:

    bool solve(TreeNode* root, int k, unordered_set<int>& st) {

        if (root == nullptr)
            return false;

        // required value
        int need = k - root->val;

        // agar required value already mil chuki hai
        if (st.find(need) != st.end())
            return true;

        // current value store karo
        st.insert(root->val);

        // left ya right subtree check karo
        return solve(root->left, k, st) ||
               solve(root->right, k, st);
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_set<int> st;

        return solve(root, k, st);
    }
};
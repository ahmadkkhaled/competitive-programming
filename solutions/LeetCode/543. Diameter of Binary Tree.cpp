class Solution {
public:

    int solve(TreeNode* node, int &ans){
        int l = 0, r = 0;

        if(node->right != NULL)
            r = 1 + solve(node->right, ans);
        if(node->left != NULL)
            l = 1 + solve(node->left, ans);

        ans = max(ans, l + r);
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
int maxDepth(TreeNode* root, int &maxi) {
    if(root == NULL) return 0;

    int ls = maxDepth(root->left, maxi);
    int rs = maxDepth(root->right, maxi);
    maxi = max(maxi, root->val + ls + rs);

    int ret = root->val + max(ls, rs);
    return ret < 0 ? 0 : ret;
}



int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxDepth(root, maxi);
    return maxi;
}

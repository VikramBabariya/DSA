int maxDepth(TreeNode* root, int &maxi) {
    if(root == NULL) return 0;

    int ld = maxDepth(root->left, maxi);
    int rd = maxDepth(root->right, maxi);
    maxi = max(maxi, ld + rd);
    return 1 + max(ld, rd);
}


int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    maxDepth(root, maxi);
    return maxi;
}

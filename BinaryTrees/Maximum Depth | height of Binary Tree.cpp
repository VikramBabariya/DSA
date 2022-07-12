// recursive

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return 1 + max(ld, rd);
}

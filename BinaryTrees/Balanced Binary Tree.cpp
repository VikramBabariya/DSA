int checkHelp(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = checkHelp(root->left);
    int rh = checkHelp(root->right);

    if(lh == -1 || rh == -1) return -1;
    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}


bool isBalanced(TreeNode* root) {
    if(checkHelp(root) != -1) return true;
    return false;
}

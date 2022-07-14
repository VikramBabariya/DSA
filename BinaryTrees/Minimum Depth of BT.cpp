int minDepthHelp(TreeNode* root) {
    if(root == NULL) return 0;

    int minL = minDepthHelp(root->left);
    int minR = minDepthHelp(root->right);

    if(minL == 0 && minR == 0) return 1;
    if(minL == 0) return 1 + minR;
    if(minR == 0) return 1 + minL;
    return 1 + min(minL, minR);
}

bool isValidBST(TreeNode* root, long l = -LONG_MAX, long r = LONG_MAX) {
    if(root == NULL) return true;
    if(root->val <= l || root->val >= r) return false;
    return isValidBST(root->left, l, root->val) && isValidBST(root->right, root->val, r);
}

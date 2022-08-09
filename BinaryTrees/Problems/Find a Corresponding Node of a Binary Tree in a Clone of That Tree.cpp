TreeNode* getRef(TreeNode* root, int &val){
    if(root == NULL) return NULL;

    if(root->val == val) return root;
    TreeNode * node = getRef(root->left, val);
    if(node) return node;
    return getRef(root->right, val);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    int val = target->val;
    return getRef(cloned, val);
}

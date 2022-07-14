bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    if(p == NULL && q == NULL) return true;

    if(p->val != q->val) return false;

    bool left = isSameTree(p->left, q->left);
    if(!left) return false;
    bool right = isSameTree(p->right, q->right);
    if(!right) return false;

    return true;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL || q == NULL) return (p == q);

    if(p->val != q->val) return false;

    bool left = isSameTree(p->left, q->left);
    if(!left) return false;
    bool right = isSameTree(p->right, q->right);
    if(!right) return false;

    return true;
}

int maxDepth(TreeNode* root, TreeNode* subRoot, int subH){
    if(root == NULL) return 0;

    int ld = maxDepth(root->left, subRoot, subH);
    if(ld == -2) return -2;
    int rd = maxDepth(root->right, subRoot, subH);
    if(rd == -2) return -2;

    int curH = 1 + max(ld, rd);
    if(curH == subH){
        if(isSameTree(root, subRoot)) return -2;
    }
    return curH;
}

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return 1 + max(ld, rd);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    int subH = maxDepth(subRoot);
    return maxDepth(root, subRoot, subH) == -2 ? true : false;
}

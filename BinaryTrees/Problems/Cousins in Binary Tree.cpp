void find(TreeNode* root, int val, int dep, TreeNode* parent, int &d, TreeNode* &p){
    if(root == NULL) return;
    if(root->val == val){
        d = dep;
        p = parent;
        return;
    }
    find(root->left, val, dep+1, root, d, p);
    if(d != -1) return;
    find(root->right, val, dep+1, root, d, p);
}


bool isCousins(TreeNode* root, int x, int y) {
    int xDep = -1, yDep = -1;
    TreeNode *xPer = NULL, *yPer = NULL;

    find(root, x, 0, NULL, xDep, xPer);
    find(root, y, 0, NULL, yDep, yPer);

    if(xDep == yDep && xPer != yPer) return true;
    return false;
}

// TC: O(N) SC: O(N)
int rob(TreeNode* root, unordered_map<TreeNode*, int> &nodeSum){
    if(root == NULL) return 0;

    if(nodeSum.count(root)) return nodeSum[root]; 

    int op1 = root->val;
    if(root->left){
        op1 += rob(root->left->left, nodeSum) + rob(root->left->right, nodeSum);
    }
    if(root->right){
        op1 += rob(root->right->left, nodeSum) + rob(root->right->right, nodeSum);
    }

    int op2 = rob(root->left, nodeSum) + rob(root->right, nodeSum);

    return nodeSum[root] = max(op1, op2);
}

int rob(TreeNode* root) {
    unordered_map<TreeNode*, int> nodeSum;
    return rob(root, nodeSum);
}

//TC: O(N) SC: (H)
int tryRob(TreeNode* root, int& l, int& r) {
    if (!root)
        return 0;

    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = tryRob(root->left, ll, lr);
    r = tryRob(root->right, rl, rr);

    return max(root->val + ll + lr + rl + rr, l + r);
}

int rob(TreeNode* root) {
    int l, r;
    return tryRob(root, l, r);
}

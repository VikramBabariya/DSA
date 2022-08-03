void LeftLeafSum(TreeNode* root, bool isLeft, int &sum){
    if(root == NULL) return;

    LeftLeafSum(root->left, true, sum);
    LeftLeafSum(root->right, false, sum);

    if((root->left == NULL && root->right == NULL) && isLeft) sum += root->val;
}

int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    LeftLeafSum(root, false, sum);
    return sum;
}

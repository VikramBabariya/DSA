int findSum(TreeNode* root, int &ans){
    if(root == NULL) return 0;

    int leftSum = findSum(root->left, ans);
    int rightSum = findSum(root->right, ans);

    ans += abs(leftSum - rightSum);
    return leftSum + rightSum + root->val;
}

int findTilt(TreeNode* root) {
    int ans = 0;
    findSum(root, ans);
    return ans;
}

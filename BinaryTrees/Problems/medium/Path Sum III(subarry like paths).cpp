unordered_map<long long, int> prefix;
int res = 0;

void dfs(TreeNode* root, int target, long long prev_sum) {
    if (!root) return;
    prev_sum += root->val;

    res += prefix[prev_sum - target];

    prefix[prev_sum]++;

    dfs(root->left, target, prev_sum);
    dfs(root->right, target, prev_sum);

    prefix[prev_sum]--;
}

int pathSum(TreeNode* root, int targetSum) {
    prefix[0]++;
    dfs(root, targetSum, 0);
    return res;
}


// simple dfs way without using map
int pathSum(TreeNode* root, int sum) {
    if(!root) return 0;
    return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int sumUp(TreeNode* root, int pre, int& sum){
    if(!root) return 0;
    int current = pre + root->val;
    return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
}

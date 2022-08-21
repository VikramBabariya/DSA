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

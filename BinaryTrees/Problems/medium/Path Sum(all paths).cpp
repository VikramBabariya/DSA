bool isLeaf(TreeNode *node){
    return node->left == NULL && node->right == NULL;
}

void allPaths(TreeNode* root, vector<int>& path, int& targetSum, vector<vector<int>>& ans){
    // base case
    path.push_back(root->val);
    targetSum -= root->val;
    if(isLeaf(root) && targetSum == 0){
        ans.push_back(path);
    }

    // s2 : exploring all pos.
    if(root->left) allPaths(root->left, path, targetSum, ans);
    if(root->right) allPaths(root->right, path, targetSum, ans);

    //backtrck
    path.pop_back();
    targetSum += root->val;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    vector<int> path;
    allPaths(root, path, targetSum, ans);
    return ans;
}

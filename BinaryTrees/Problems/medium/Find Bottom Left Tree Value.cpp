// dfs way -- TC:O(N)  SC:O(H)
void dfs(TreeNode* root, int dep, int &maxDep, int &ans){
    if(root == NULL) return;

    if(dep > maxDep){
        ans = root->val;
        maxDep = dep;
    }
    dfs(root->left, dep+1, maxDep, ans);
    dfs(root->right, dep+1, maxDep, ans);
}


int findBottomLeftValue(TreeNode* root) {
    int maxDep = -1, ans;
    dfs(root, 0, maxDep, ans);
    return ans;
}

// bfs way -- TC:O(N) SC:O(N)
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        root=q.front();
        q.pop();
        if (root->right) {
            q.push(root->right);
        }
        if(root->left) q.push(root->left);
    }
    return root->val;
}

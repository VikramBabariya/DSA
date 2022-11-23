vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){ 
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
        ans.push_back(node->val);  
    }
    return ans;
}

//dfs way | tc:o(n), sc:o(h)
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return 1 + max(ld, rd);
}

void dfs(TreeNode* root, int depth, vector<vector<int>> &lot){
    if(root == NULL) return;

    dfs(root->left, depth+1, lot);
    dfs(root->right, depth+1, lot);
    lot[depth].push_back(root->val);
}


vector<vector<int>> levelOrder(TreeNode* root) {
    int d = maxDepth(root);
    vector<vector<int>> lot(d);
    dfs(root, 0, lot);
    return lot;
}

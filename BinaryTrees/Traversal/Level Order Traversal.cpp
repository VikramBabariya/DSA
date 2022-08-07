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

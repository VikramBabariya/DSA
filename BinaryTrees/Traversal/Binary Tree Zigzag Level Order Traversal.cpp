vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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

    int n = ans.size();
    for(int i = 1; i < n; i+=2){
        reverse(begin(ans[i]), end(ans[i]));   
    }
    return ans;
}

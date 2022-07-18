vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int qsize = q.size();
        vector<int> level(qsize);
        for(int i = 0; i < qsize; i++){ 
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);

            int ind = (leftToRight) ? i : qsize - i - 1;
            level[ind] = node->val;
        }
        ans.push_back(level);
        leftToRight = !leftToRight;
    }

    return ans;
}

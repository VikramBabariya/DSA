// recursive

int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return 1 + max(ld, rd);
}

// level order way
int maxDepth(TreeNode* root) {
    int maxdep = 0;
    if(root == NULL) return maxdep;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){ 
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        maxdep++;
    }
    return maxdep;
}

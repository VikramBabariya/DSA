// dfs (inorder)
int minDepth(TreeNode* root) {
    if(root == NULL) return 0;

    int minL = minDepth(root->left);
    int minR = minDepth(root->right);

    if(minL == 0) return 1 + minR;
    if(minR == 0) return 1 + minL;
    return 1 + min(minL, minR);
}

// bfs (lot)


int minDepth(TreeNode* root) {
    if(!root) return 0;

    int level = 0;
    queue<TreeNode*> q;
    int level = 0;

    q.push(root);
    while(!q.empty()){
        int breadth = q.size();
        level++;
        for(int i=0; i<breadth; i++){
            TreeNode* parent = q.front(); 
            q.pop();

            if(parent->left) q.push(parent->left);
            if(parent->right) q.push(parent->right);

            if(!parent->left && !parent->right) return level; //leaf node
        }
    }

    return level;
}

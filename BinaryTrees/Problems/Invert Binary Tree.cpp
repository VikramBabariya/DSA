// bfs 
TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;        
    queue<TreeNode*> q{{root}}; 
    while(!q.empty()){
        auto node = q.front();q.pop();            
        swap(node->left, node->right);
        for(auto& e: {node->left, node->right}) if(e) q.push(e);                    
    }
    return root;
}

//dfs 
TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return NULL;

    if(root->left != NULL) invertTree(root->left);
    if(root->right != NULL) invertTree(root->right);

    swap(root->left, root->right);
    return root;
}

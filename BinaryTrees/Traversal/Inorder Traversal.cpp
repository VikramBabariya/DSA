// recursive way
void Travers(TreeNode* root, vector<int> &intrv){
    if(root == NULL) return;
    
    Travers(root->left, intrv);
    intrv.push_back(root->val);
    Travers(root->right, intrv);
}


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> intrv;
    Travers(root, intrv);
    return intrv;
}

// iterative way

// recursive way
void Travers(TreeNode* root, vector<int> &pretrv){
    if(root == NULL) return;
    
    pretrv.push_back(root->val);
    Travers(root->left, pretrv);
    Travers(root->right, pretrv);
}


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pretrv;
    Travers(root, pretrv);
    return pretrv;
}


// iterative way

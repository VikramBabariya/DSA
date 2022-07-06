// recursive way
void Travers(TreeNode* root, vector<int> &posttrv){
    if(root == NULL) return;
    
    Travers(root->left, posttrv);
    Travers(root->right, posttrv);
    posttrv.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> posttrv;
    Travers(root, posttrv);
    return posttrv;
}

// iterative way

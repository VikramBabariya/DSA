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
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pretrv;
    if(root == NULL) return pretrv;

    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        pretrv.push_back(node->val);
        if(node->right != NULL) st.push(node->right);            
        if(node->left != NULL) st.push(node->left);   
    }
    return pretrv;
}

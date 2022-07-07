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
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> intrv;
    stack<TreeNode*> st;
    TreeNode* node = root;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            intrv.push_back(node->val);
            node = node->right;
        }
    }
    return intrv;
}

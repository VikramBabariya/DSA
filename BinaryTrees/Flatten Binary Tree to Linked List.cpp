// sol1 : SC = O(N), recursive
TreeNode* prevFlat = NULL;
void flatten(TreeNode* root) {
    if(root == NULL) return;

    flatten(root->right);
    flatten(root->left);

    root->right = prevFlat;
    root->left = NULL;
    prevFlat = root;
}

// sol2 : SC = O(1), concept : thredead BT
void flatten(TreeNode* root) {
    while(root){
        if(root->left){
            TreeNode* temp = root->left;
            while(temp->right) temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

//sol3 SC = O(N), iterative
void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);

    while(st.size()){
        TreeNode *node = st.top();
        st.pop();

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

        if(st.size()) node->right = st.top();
        node->left = NULL;
    }
}

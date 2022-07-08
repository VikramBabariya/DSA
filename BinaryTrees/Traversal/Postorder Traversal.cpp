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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> posttrv;
    if(root == NULL) return posttrv;
    stack<TreeNode*> st1;
    st1.push(root);
    TreeNode *node;

    while(!st1.empty()){
        node = st1.top();
        st1.pop();
        posttrv.push_back(node->val);
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
    }
    reverse(begin(posttrv), end(posttrv));
    return posttrv;
}

// using one stack


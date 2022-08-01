bool isLeaf(TreeNode *node){
    return node->left == NULL && node->right == NULL;
}

bool hasPathSum(TreeNode* root, int targetSum) { //s1: problem in terms of root, tsum ==> is there any path from root to leaf which has sum tsum.
    // base case
    if(root == NULL) return false;
    if(isLeaf(root) && (targetSum - root->val) == 0) return true;
    
    // s2 : exploring all pos.
    bool pos1 = hasPathSum(root->left, targetSum - root->val);
    bool pos2 = hasPathSum(root->right, targetSum - root->val);
  
    //s3 : returnning ans based on question.
    return pos1 || pos2;
}

// iterative using stack
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    stack<pair<TreeNode*, int>> st;
    st.push({root, root->val});

    while(!st.empty()){
        auto it = st.top();
        TreeNode *node = it.first;
        int sum = it.second;
        st.pop();

        if(node->right) st.push({node->right, sum + node->right->val});
        if(node->left) st.push({node->left, sum + node->left->val});

        if(isLeaf(node) && sum == targetSum) return true;
    }
    return false;
}

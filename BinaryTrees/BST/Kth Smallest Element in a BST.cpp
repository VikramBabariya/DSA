//TC:O(N) , SC:O(height)

int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
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
            cnt++;
            if(cnt == k) return node->val;
            node = node->right;
        }
    }
    return -1;
}


//sol2: Binary Search Approach

int count(TreeNode *root){  // counting the number of nodes in the tree
    if(root == NULL)
        return 0;

    return (1 + count(root->left) + count(root->right));
}

int kthSmallest(TreeNode* root, int k) {
    TreeNode *curr = root;
    int curr_rank = count(curr->left) + 1;

    while(curr_rank != k){
        if(curr_rank > k){
            curr = curr->left;  // here curr will never be null
            curr_rank = curr_rank - count(curr->right) - 1;
        }else{
            curr = curr->right; // here also curr will never be null
            curr_rank = curr_rank + count(curr->left) + 1;
        }
    }

    return curr->val;
}

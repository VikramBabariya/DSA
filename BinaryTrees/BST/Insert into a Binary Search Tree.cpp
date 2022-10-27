TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    TreeNode* temp = root;

    if(root == NULL) return newNode;

    while(1){
        if(temp->val < val){
            if(temp->right == NULL){
                temp->right = newNode;
                return root;
            }
            temp = temp->right;
        }
        else{
            if(temp->left == NULL){
                temp->left = newNode;
                return root;
            }
            temp = temp->left;
        }
    }
    return root;
}

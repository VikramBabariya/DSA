int leftH(TreeNode* root){
    int h = 0;
    while(root){
        h++;
        root = root->left;
    }
    return h;
}

int rightH(TreeNode* root){
    int h = 0;
    while(root){
        h++;
        root = root->right;
    }
    return h;
}


int countNodes(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = leftH(root);
    int rh = rightH(root);

    if(lh == rh) return (1<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

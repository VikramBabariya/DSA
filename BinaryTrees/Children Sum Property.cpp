int childSum(BinaryTreeNode < int > * root){
    int childSum = 0;
    if(root->left) childSum += (root->left)->data;
    if(root->right) childSum += (root->right)->data;
    return childSum;
}

void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    
    int cs = childSum(root);
    if(cs < root->data){
        if(root->left) (root->left)->data = root->data;
        if(root->right) (root->right)->data = root->data;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int tot = childSum(root);
    if(root->left || root->right) root->data = tot;   
}  

// O(NLogN) SC: O(Logn)
//recursive
Node* connect(Node* root) {
    if(root == NULL) return root;
    if(root->left == NULL && root->right == NULL) return root;

    (root->left)->next = root->right;
    Node *temp1 = root->left, *temp2 = root->right;
    while(temp1->right && temp2->left){
        temp1 = temp1->right; temp2 = temp2->left;
        temp1->next = temp2;
    }

    connect(root->left);
    connect(root->right);
    return root;
}

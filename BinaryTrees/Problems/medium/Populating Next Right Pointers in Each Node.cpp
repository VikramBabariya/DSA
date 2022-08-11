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

//Iterative TC: O(N) SC: O(N)
    Node* connect(Node* root) {
    if(root == NULL) return root;
    if(!root->left && !root->right) return root;

    queue<Node*> q;
    q.push(root->left); q.push(root->right);
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){ 
            Node *node = q.front(); q.pop();
            if(i < qsize-1) node->next = q.front();

            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return root;
 }

//iterative TC:O(N) SC:O(1)
TreeLinkNode* connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
    return root;
}

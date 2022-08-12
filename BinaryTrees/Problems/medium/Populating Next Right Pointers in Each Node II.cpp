Node *getPrev(Node *root){
    while(root){
        if(root->left) return root->left;
        if(root->right) return root->right;
        root = root->next;
    }
    return NULL;
}

Node *getNext(Node *root){
    while(root){
        if(root->left || root->right) return root;
        root = root->next;
    }
    return NULL;
}


Node* connect(Node* root) {
    Node *prev = root;

    while(prev){
        Node *cur = prev;
        while(1){
            if(cur->left && cur->right){
                cur->left->next = cur->right;
            }
            Node *tempCur = getNext(cur->next); if(!tempCur) break;
            if(cur->left && !cur->right){
                cur->left->next = tempCur->left != NULL ? tempCur->left : tempCur->right;
            }
            else if(cur->right){
                cur->right->next = tempCur->left != NULL ? tempCur->left : tempCur->right;
            }
            cur = tempCur;
        }
        prev = getPrev(prev);
    }
    return root;
}

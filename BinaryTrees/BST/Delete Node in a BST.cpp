//TC:O(height)


TreeNode *find_suc(TreeNode *root){
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL)
        return NULL;

    TreeNode *head = new TreeNode();
    head->right = root;
    head->left = head;

    TreeNode *parent = head, *target = root;
    char dir = 'r';

    while(target != NULL){
        if(target->val == key){

            /*if(target->left == NULL){
               if(dir == 'r'){
                   parent->right = target->right;
               }else{
                   parent->left = target->right;
               }
               delete target;
               return head->right;
           }*/
           if(target->right == NULL){
               if(dir == 'r'){
                   parent->right = target->left;
               }else{
                   parent->left = target->left;
               }
               delete target;
               return head->right;
           }

           TreeNode *suc = find_suc(target);
           suc->left = target->left;
           if(dir == 'r'){
               parent->right = target->right;
           }else{
               parent->left = target->right;
           }
           delete target;
           return head->right;



        }else if(target->val > key){
            parent = target;
            target = target->left;
            dir = 'l';
        }else if(target->val < key){
            parent = target;
            target = target->right;
            dir = 'r';
        }
    }

    return head->right;
}

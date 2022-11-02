//TC:O(Height) , SC:O(1)


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *curr = root;
    while(1){
        if(curr->val > p->val && curr->val > q->val){
            curr = curr->left;
        }else if(curr->val < p->val && curr->val < q->val){
            curr = curr->right;
        }else{
            return curr;
        }
    }
    return NULL;
}

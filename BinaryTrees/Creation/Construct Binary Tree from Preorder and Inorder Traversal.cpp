TreeNode* build(vector<int>& preorder, int prestart, int preend,
               vector<int>& inorder, int instart, int inend, unordered_map<int, int> &valInd){
    if(prestart > preend || instart > inend) return NULL;

    TreeNode* root = new TreeNode(preorder[prestart]);
    int inroot = valInd[preorder[prestart]];
    int numleft = inroot - instart;

    root->left = build(preorder, prestart+1, prestart + numleft,
                      inorder, instart, inroot-1, valInd);
    root->right = build(preorder, prestart + numleft + 1, preend,
                       inorder, inroot+1, inend, valInd);
    return root;

}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> valInd;
    int ps = preorder.size(), is = inorder.size();
    for(int i = 0; i < is; i++){
        valInd[inorder[i]] = i;
    }

    return build(preorder, 0, ps-1, inorder, 0, is-1, valInd); 
}

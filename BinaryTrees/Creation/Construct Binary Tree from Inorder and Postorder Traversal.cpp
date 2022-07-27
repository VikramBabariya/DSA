TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder,
               int poststart, int postend, unordered_map<int, int> &valInd){
    if(instart > inend || poststart > postend) return NULL;

    TreeNode* root = new TreeNode(postorder[postend]);
    int inroot = valInd[postorder[postend]];
    int leftCnt = inroot - instart;

    root->left = build(inorder, instart, inroot - 1, postorder,
                      poststart, poststart + leftCnt - 1, valInd);
    root->right = build(inorder, inroot + 1, inend, postorder,
                       poststart + leftCnt, postend - 1, valInd);
    return root;  
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> valInd;
    int n = inorder.size(), m = postorder.size();

    for(int i = 0; i < n; i++){
        valInd[inorder[i]] = i;
    }

    return build(inorder, 0, n-1, postorder, 0, m-1, valInd);
}

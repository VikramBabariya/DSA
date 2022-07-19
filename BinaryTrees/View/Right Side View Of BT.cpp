void rsv(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);

    rsv(root->right, level+1, ans); // just change this two line for left side view 
    rsv(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rsv(root, 0, ans);
    return ans;
}

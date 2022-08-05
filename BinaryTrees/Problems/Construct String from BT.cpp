string tree2str(TreeNode* root) {
    if(root == NULL) return "";

    string leftStr = tree2str(root->left);
    string rightStr = tree2str(root->right);

    string ans = to_string(root->val);
    if(leftStr.size() == 0 && rightStr.size() == 0) return ans;
    ans.push_back('('); ans += leftStr; ans.push_back(')');
    if(rightStr.size() == 0) return ans;
    ans.push_back('('); ans += rightStr; ans.push_back(')');
    return ans;
}

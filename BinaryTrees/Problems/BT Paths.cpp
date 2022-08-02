void findPaths(TreeNode* root, string &path, vector<string> &ans){
    if(root == NULL) return;

    string temp = path;
    path += to_string(root->val) + "->";
    findPaths(root->left, path, ans);
    findPaths(root->right, path, ans);

    if(root->left == NULL && root->right == NULL){ // leaf
        path.pop_back(); path.pop_back();
        ans.push_back(path);
    }
    path = temp;
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string path = "";
    findPaths(root, path, ans);
    return ans;
}

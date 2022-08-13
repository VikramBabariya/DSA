// O(N^2)
int BinToInt(vector<bool> &bin){
    int res = 0;
    for(int i = bin.size()-1, cnt = 0; i >= 0 ; i--, cnt++){
        res += bin[i] * pow(2, cnt);
    }
    return res;
}

void sumBT(TreeNode* root, vector<bool> &path, int &sum){
    if(root == NULL) return;

    path.push_back(root->val);
    sumBT(root->left, path, sum);
    sumBT(root->right, path, sum);

    if(root->left == NULL && root->right == NULL){
        sum += BinToInt(path);
    }
    path.pop_back();
}

int sumRootToLeaf(TreeNode* root) {
    int sum = 0;
    vector<bool> path;
    sumBT(root, path, sum);
    return sum;
}

// O(N)
int sumRootToLeaf(TreeNode* root, int val = 0) {
    if(root == NULL) return 0;
    val = 2 * val + root->val; // for decimal use val = 10 * val + root->val;
    return (root->left == NULL && root->right == NULL) ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
}


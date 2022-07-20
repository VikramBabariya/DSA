int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    queue<pair<TreeNode*, ll>> q;
    q.push({root, 0});
    ll maxi = 0;

    while(q.size()){
        ll qsize = q.size(), minInd = q.front().second;
        ll first, last;

        for(int i = 0; i < qsize; i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            ll ind = it.second - minInd;
            if(i == 0) first = ind;
            if(i == qsize-1) last = ind;

            if(node->left) q.push({node->left, 2*ind + 1});
            if(node->right) q.push({node->right, 2*ind + 2});      
        }
        maxi = max(maxi, last - first + 1);
    }
    return maxi;
}

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL) return ans;
    
    map<int, int> mp; // vertical - node value
    queue<pair<TreeNode<int> *, int>> q; // node - vertical
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        TreeNode<int> * node = it.first;
        int ver = it.second;
        q.pop();
        
        if(!mp.count(ver)) mp[ver] = node->val;
        
        if(node->left) q.push({node->left, ver-1});
        if(node->right) q.push({node->right, ver+1});
    }
    for(auto &it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

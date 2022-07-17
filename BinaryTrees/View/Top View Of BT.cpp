vector<vector<pair<int, int>>> UpdatedLevelOrder(TreeNode<int> * root, int &minVer, int &maxVer) {
    vector<vector<pair<int, int>>> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode<int> *, int>> q; // node, ver
    q.push({root, 0});
    while(!q.empty()){
        vector<pair<int, int>> level;
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){ 
            auto it = q.front();
            TreeNode<int> *node = it.first;
            int ver = it.second;
            minVer = min(minVer, ver);
            maxVer = max(maxVer, ver);
            q.pop();
            if(node->left != NULL) q.push({node->left, ver-1});
            if(node->right != NULL) q.push({node->right, ver+1});
            level.push_back({node->val, ver});
        }
        ans.push_back(level);
    }

    return ans;
}

vector<vector<int>> verticalTraversal(TreeNode<int> * root) {
    int minVer = INT_MAX, maxVer = INT_MIN;
    vector<vector<pair<int, int>>> lot = UpdatedLevelOrder(root, minVer, maxVer);
    
    int n = abs(minVer) + maxVer + 1;
    vector<vector<int>> ans(n);

    for(int i = 0; i < lot.size(); i++){
        for(int j = 0; j < lot[i].size(); j++){
            int t = lot[i][j].second + abs(minVer);
            ans[t].push_back(lot[i][j].first);
        }
    }

    return ans;
}
/*****************/ //updated part
vector<int> getTopView(TreeNode<int> *root) {
    vector<vector<int>> vot = verticalTraversal(root);
    vector<int> ans;
    
    for(auto ver : vot){
        ans.push_back(ver[0]);
    }
    return ans;  
}

//approach 1
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> grid;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while(!q.empty()){
        auto point = q.front();
        q.pop();
        TreeNode* node = point.first;
        int ver = point.second.first, lev = point.second.second;

        grid[ver][lev].insert(node->val);
        if(node->left){
            q.push({node->left, {ver-1, lev+1}});
        }
        if(node->right){
            q.push({node->right, {ver+1, lev+1}});
        }
    }

    vector<vector<int>> ans;
    for(auto &verMap: grid){
        vector<int> vertical;

        for(auto levMap: verMap.second){
            vertical.insert(vertical.end(), levMap.second.begin(), levMap.second.end());
        }
        ans.push_back(vertical);
    }
    return ans;
}

// approach 2
vector<vector<pair<int, int>>> UpdatedLevelOrder(TreeNode* root, int &minVer, int &maxVer) {
    vector<vector<pair<int, int>>> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*, int>> q; // node, ver
    q.push({root, 0});
    while(!q.empty()){
        vector<pair<int, int>> level;
        int qsize = q.size();
        for(int i = 0; i < qsize; i++){ 
            auto it = q.front();
            TreeNode *node = it.first;
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

static bool comp(pair<int, int> &p1, pair<int, int> &p2){
    return p1.first < p2.first;
}



vector<vector<int>> verticalTraversal(TreeNode* root) {
    int minVer = INT_MAX, maxVer = INT_MIN;
    vector<vector<pair<int, int>>> lot = UpdatedLevelOrder(root, minVer, maxVer);

    for(int i = 0; i < lot.size(); i++){
        sort(begin(lot[i]), end(lot[i]), comp);
    }

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

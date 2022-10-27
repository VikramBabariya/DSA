void trackParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents){
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode* currNode = q.front();
        q.pop();
        if(currNode->left){
            parents[currNode->left] = currNode;
            q.push(currNode->left);
        }
        if(currNode->right){
            parents[currNode->right] = currNode;
            q.push(currNode->right);
        }
    }
}


vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parents;
    trackParents(root, parents);

    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int currDist = 0;

    while(q.size()){
        int qsize = q.size();
        if(currDist == k) break; currDist++;

        for(int i = 0; i < qsize; i++){
            TreeNode *node = q.front();
            q.pop();

            if(node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents[node] && !visited[parents[node]]){
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
    }
    vector<int> ans;
    while(q.size()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

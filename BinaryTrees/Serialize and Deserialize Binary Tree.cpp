// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL) return "";

    string ser = "";
    queue<TreeNode*> q;
    q.push(root);

    while(q.size()){
        TreeNode* node = q.front();
        q.pop();

        if(node == NULL){
            ser += "null,";
        }else{
            ser += to_string(node->val) + ",";
            q.push(node->left); // will push null also in the queue because at place of null we want to have null in string.
            q.push(node->right);
        }
    }
    cout<<ser<<endl;
    return ser;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data == "") return NULL;

    stringstream ss(data);
    string sub;
    queue<TreeNode*> q;
    getline(ss, sub, ',');
    TreeNode* root = new TreeNode(stoi(sub));
    q.push(root);

    while(q.size()){
        TreeNode* node = q.front();
        q.pop();

        getline(ss, sub, ',');
        if(sub != "null"){ // if sub is null, then our node already have its left and right child as null.
            TreeNode* leftNode = new TreeNode(stoi(sub));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(ss, sub, ',');
        if(sub != "null"){
            TreeNode* rightNode = new TreeNode(stoi(sub));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

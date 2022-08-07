// O(H) space : comparing leaf by leaf
int nextLeaf(stack<TreeNode*> &s){
    while(true){
        auto node = s.top(); s.pop();
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
        if(!node->left && !node->right) return node->val;
    }
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    s1.push(root1); s2.push(root2);

    while(s1.size() && s2.size())
        if(nextLeaf(s1) != nextLeaf(s2)) return false;

    return s1.empty() && s2.empty();
}

// O(N) : get both trees leafs in vector and compare vactors.

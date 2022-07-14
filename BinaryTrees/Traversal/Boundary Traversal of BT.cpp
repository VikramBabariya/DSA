#include<bits/stdc++.h>

bool isLeaf(TreeNode<int>* root){
    if(root == NULL) return false;
    return (root->left == NULL && root->right == NULL);
}

void addLeftBound(TreeNode<int>* node, vector<int> &ans){
    while(node != NULL){
        if(!isLeaf(node)) ans.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void addRightBound(TreeNode<int>* node, vector<int> &ans){
    stack<int> st;
    while(node != NULL){
        if(!isLeaf(node)) st.push(node->data);
        if(node->right) node = node->right;
        else node = node->left;
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

void addLeafs(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    if(isLeaf(root)) ans.push_back(root->data);
    addLeafs(root->left, ans);
    addLeafs(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBound(root->left, ans);
    addLeafs(root, ans);
    addRightBound(root->right, ans);
    return ans;
}

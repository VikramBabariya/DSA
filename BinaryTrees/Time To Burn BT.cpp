#include<bits/stdc++.h>
BinaryTreeNode<int>* trackParent(BinaryTreeNode<int>* root, int start, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent){
    BinaryTreeNode<int>* target;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(q.size()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        if(node->data == start) target = node;
        if(node->left){
            parent[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    return target;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    BinaryTreeNode<int>* target = trackParent(root, start, parent);
    
    queue<BinaryTreeNode<int>*> q;
    unordered_map<BinaryTreeNode<int>*, bool> vis;
    q.push(target);
    vis[target] = true;
    int time = 0;
    
    while(q.size()){
        int qs = q.size();
        bool burn = false;
        for(int i = 0; i < qs; i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                vis[node->left] = true;
                q.push(node->left);
                burn = true;
            }
            if(node->right && !vis[node->right]){
                vis[node->right] = true;
                q.push(node->right);
                burn = true;
            }
            if(parent[node] && !vis[parent[node]]){
                vis[parent[node]] = true;
                q.push(parent[node]);
                burn = true;
            }
        }
        if(burn) time++;
    }
    return time;
}

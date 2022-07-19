if(node1 == NULL || node2 == NULL) return node1 == node2;

    if(node1->val != node2->val) return false;

    return isSym(node1->left, node2->right) && isSym(node1->right, node2->left);
}


bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return isSym(root->left, root->right);
}

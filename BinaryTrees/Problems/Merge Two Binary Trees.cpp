TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL && root2 == NULL) return NULL;
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;

    TreeNode* leftMerge = mergeTrees(root1->left, root2->left);
    TreeNode* rightMerge = mergeTrees(root1->right, root2->right);

    TreeNode* mergedNode = new TreeNode(root1->val + root2->val);
    mergedNode->left = leftMerge;
    mergedNode->right = rightMerge;
    return mergedNode;
}

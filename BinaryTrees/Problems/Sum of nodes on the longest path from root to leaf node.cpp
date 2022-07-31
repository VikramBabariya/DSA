bool isLeaf(Node *node){
    if(node == NULL) return false;
    return (node->left == NULL && node->right == NULL);
}

void longPathSum(Node *node, int &sum, int &dep, int &maxDep, int &maxSum){
    if(node == NULL) return;

    sum += node->data;
    dep += 1;
    longPathSum(node->left, sum, dep, maxDep, maxSum);
    longPathSum(node->right, sum, dep, maxDep, maxSum);

    if(isLeaf(node)){
        if(dep > maxDep){
            maxSum = sum;
            maxDep = dep;
        }else if(dep == maxDep){
            maxSum = max(maxSum, sum);
        }
    }
    sum -= node->data;
    dep -= 1;
}

int sumOfLongRootToLeafPath(Node *root)
{
    int sum = 0, dep = 0, maxSum = -1, maxDep = -1;
    longPathSum(root, sum, dep, maxDep, maxSum);
    return maxSum;
}

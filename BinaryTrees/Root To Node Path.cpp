bool findPath(TreeNode* node, vector<int> &arr, int x){
     if(node == NULL) return false;
     
     arr.push_back(node->val);
     if(node->val == x) return true;
     
     if(findPath(node->left, arr, x) || findPath(node->right, arr, x)) return true;
     
     arr.pop_back();
     return false;
 }
 
vector<int> solve(TreeNode* A, int B) {
    vector<int> arr;
    findPath(A, arr, B);
    return arr;
}

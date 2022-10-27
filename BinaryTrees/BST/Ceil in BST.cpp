int findCeil(Node* root, int val) {
  int cl = -1;
  while(root){
      if(root->data == val) return val;
      if(root->data <= val) root = root->right;
      else{
          cl = root->data;
          root = root->left;
      }
  }
  return cl;
}

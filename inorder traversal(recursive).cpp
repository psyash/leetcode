void inorder(node* root, vector<int> &nodes){
  if(root==NULL){
    return;
  }

  inorder(root->left,nodes);
  nodes.push_back(root->val);
  inorder(root->right,node);
}
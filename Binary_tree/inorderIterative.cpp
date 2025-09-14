class Soltuion{
    public : 
      vector<int> inorderTraversal(TreeNode* root){
          vector<int> res;
          stack<TreeNode*> st;
          TreeNode* curr = root;
          
          while(curr != NULL || !st.empty()){
              if(curr!= NULL){
                 st.push(curr);
                 curr = curr->left;
                }else{
                  curr = st.top();
                  st.pop();
                  res.push_back(curr->val);
                  curr = curr->right;
          }
          return res;
      }
}
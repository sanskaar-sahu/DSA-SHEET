#include<bits/stdc++.h>
using namespace std;       
    
   int height(TreeNode * root , int& diameter){
        if(!root) return 0;
        int lh = height(root->left , diameter);
        int rh = height(root->right , diameter);
        return 1 + max(lh , rh);
    }
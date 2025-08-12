#include <bits/stdc++.h> 

//Q- https://www.naukri.com/code360/problems/ceil-from-bst_920464?leftPanelTabValue=SUBMISSION


/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    if(!node) return -1;
    BinaryTreeNode<int>* temp = node;
    int ceil = -1;

    while(temp){
        if(temp->data ==x){
            return temp->data;
        }else if(temp->data >x){
            ceil = temp->data;
            temp = temp->left;
        }else if(temp->data < x){
            temp = temp->right;
        }
    }

    return ceil;    
}
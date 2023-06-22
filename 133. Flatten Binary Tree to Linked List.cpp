#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* flatten(TreeNode<int>* root,TreeNode<int>* &prev){
    if(root==NULL){
            return root; 
    }
    flatten(root->right,prev);
    flatten(root->left,prev);
       
    root->right= prev;
    root->left=NULL;
    prev= root;
    return root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root){
//   TreeNode<int>* prev=NULL;
//     return flatten(root,prev);
    TreeNode<int>* curr=root;
    while(curr){
        if(curr->left){
            TreeNode<int>* prev=curr->left;
            while(prev->right)prev=prev->right;
            prev->right=curr->right;
            curr->right=curr->left;
        }
        curr=curr->right;
    }
    return root;
}
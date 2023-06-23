#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
   if(root==NULL)return true;
   if(root->left==NULL && root->right==NULL)return true;
   if((root->left &&root->left->data>root->data) || ( root->right && root->right->data<root->data))return false;
   bool left=validateBST(root->left);
   bool right=validateBST(root->right);
   if(!left|| !right)return false;
   return true;
}
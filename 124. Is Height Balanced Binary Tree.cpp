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
int height(BinaryTreeNode<int>* root){
    if(root==NULL)return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)>1)return -1;
    if(lh==-1 || rh==-1)return -1;
    return 1+max(lh,rh);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    int x=height(root);
    if(x==-1)return false;
    return true;
}
#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{   BinaryTreeNode<int>* curr=root;
    pair<int,int> ans={-1,-1};
    while(root!=NULL){
        if(key>=root->data){
            root=root->right;
        }
        else{
            ans.second=root->data;
            root=root->left;
        }
    }
      while(curr!=NULL){
        if(key>curr->data){
            ans.first=curr->data;
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    return ans;
}

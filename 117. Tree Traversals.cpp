#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void Traversal(BinaryTreeNode<int>* root,vector<int> &pre,vector<int> &ino,vector<int>& post){
    if(root==NULL)return;
    pre.push_back(root->data);
    Traversal(root->left,pre,ino,post);
    ino.push_back(root->data);
    Traversal(root->right,pre,ino,post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    vector<int> pre;
    vector<int> ino;
    vector<int> post;
    Traversal(root,pre,ino,post);
    ans={ino,pre,post};
    return ans;
}
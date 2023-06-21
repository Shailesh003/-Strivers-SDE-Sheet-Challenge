#include <bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* BuildTree(vector<int> &postorder,int poststart,int postend,vector<int> &inorder
,int instart,int inend,map<int,int> &mp){
     if(poststart>postend|| instart>inend)return NULL;
     TreeNode<int>* root=new TreeNode<int>(postorder[postend]);
     int inroot=mp[root->data];
     int numleft=inroot-instart;
     root->left=BuildTree(postorder, poststart, poststart+numleft-1,inorder,instart,inroot-1, mp);
     root->right=BuildTree(postorder, poststart+numleft,postend-1,inorder,inroot+1,inend, mp);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	map<int,int> mp;
     for(int i=0;i<inorder.size();i++){
          mp[inorder[i]]=i;
     }
     TreeNode<int>* root=BuildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
     return root;
}

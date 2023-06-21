#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

// ************************************************************/
// TreeNode<int> *BuildTree(vector<int> &preorder,int prestart,int preend,vector<int> &inorder
// ,int instart,int inend,map<int,int> mp){
//     if(prestart>preend|| instart>inend)return NULL;
//     TreeNode<int>* root;
//     root= new TreeNode<int>(preorder[prestart]);
//     int inroot=mp[root->data];
//     int numleft=inroot-instart;
//     root->left=BuildTree(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,mp);
//     root->right=BuildTree(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,mp);
//     return root;
// }
// TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
// {   if(inorder.size()!=preorder.size()|| inorder.size()==0 || preorder.size()==0)return NULL;
//     map<int,int> mp;
//     for(int i=0;i<inorder.size();i++){
//         mp[inorder[i]]=i;
//     }
// 	TreeNode<int>* root=BuildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
//     return root;
// }
void createMapping(vector<int> &inorder, unordered_map<int,vector<int>> &nodeToIndex, int n)
{
    for(int i=0;i<n;i++)
    {
        nodeToIndex[inorder[i]].push_back(i);
    }
}
    
TreeNode<int>* solve(vector<int> &inorder, vector<int> &preorder, int n, int &preIndex, int inOrderStart, int inOrderEnd, unordered_map<int,vector<int>> &nodeToIndex)
{
    // base case
    if(preIndex>=n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
        
    int element=preorder[preIndex++];
    TreeNode<int>* root=new TreeNode<int>(element);
        
    int position=-1;
    if(nodeToIndex[element][0]==INT_MIN)
    {
        position=nodeToIndex[element][1];
        nodeToIndex[element][1]=INT_MIN;
    }
    else
    {
        position=nodeToIndex[element][0];
        nodeToIndex[element][0]=INT_MIN;
    }
        
    // Recursive Calls
    root->left=solve(inorder, preorder, n, preIndex, inOrderStart, position-1, nodeToIndex);
    
    root->right=solve(inorder, preorder, n, preIndex, position+1, inOrderEnd, nodeToIndex);
        
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    
    int n=inorder.size();
    int preIndex=0;
    
    unordered_map<int,vector<int>> nodeToIndex;
        
    // creating nodes to index mapping
    createMapping(inorder, nodeToIndex, n);
        
    TreeNode<int>* ans=solve(inorder, preorder, n, preIndex, 0, n-1, nodeToIndex);
        
    return ans;
}
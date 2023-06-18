#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root==NULL)return ans;
    queue<pair<BinaryTreeNode<int>*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        auto node=temp.first;
        int x=temp.second;
        mp[x]=node->data;
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}

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

************************************************************/
void LeftView(TreeNode<int>* root,int lvl,vector<int> &ans){
    if(root==NULL)return;
    if(ans.size()==lvl)ans.push_back(root->data);
    LeftView(root->left,lvl+1,ans);
    LeftView(root->right,lvl+1,ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
//   vector<int> ans;
//   if(root==NULL)return ans;
//   queue<pair<TreeNode<int>*,int>> q;
//   map<int,int>mp;
//   q.push({root,0});
//   while(!q.empty()){
//       auto it=q.front();
//       q.pop();
//       auto node=it.first;
//       auto lvl=it.second;
//       if(mp.find(lvl)==mp.end())mp[lvl]=node->data;
//       if(node->left)q.push({node->left,lvl+1});
//       if(node->right)q.push({node->right,lvl+1});
//   }
//   for(auto it:mp){
//       ans.push_back(it.second);
//   }
//   return ans;
//optimal
    // vector<int> ans;
    // if(root==NULL)return ans;
    // queue<TreeNode<int>*> q;
    // q.push(root);
    // while(!q.empty()){
    //     int size=q.size();
    //     for(int i=0;i<size;i++){
    //         TreeNode<int>* temp=q.front();
    //         q.pop();
    //         if(i==0)ans.push_back(temp->data);
    //         if(temp->left)q.push(temp->left);
    //         if(temp->right)q.push(temp->right);
    //     }
    // }
    // return ans;
    //recursive approach
    vector<int> ans;
    LeftView(root,0,ans);
    return ans;
}
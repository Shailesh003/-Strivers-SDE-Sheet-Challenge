#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root==NULL)return ans;
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> mp;
    q.push({root, 0});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        int x=temp.second;
        TreeNode<int>* node=temp.first;
        if(mp.find(x)==mp.end())mp[x]=node->val;
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;

}
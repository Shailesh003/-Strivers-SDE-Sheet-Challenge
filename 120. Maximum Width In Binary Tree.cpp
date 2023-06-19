#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

int getMaxWidth(TreeNode<int> *root)
{   if(root==NULL)return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        int lvl=0;
        for(int i=0;i<size;i++){
            TreeNode<int> *node=q.front();
            q.pop();
            lvl++;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans=max(ans,lvl);
    }
    return ans;
}
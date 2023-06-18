#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void Preorder(TreeNode* root,vector<int> &ans){
    if(root==NULL)return;
    ans.push_back(root->data);
    Preorder(root->left,ans);
    Preorder(root->right,ans);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    // Preorder(root,ans);
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* top=st.top();
        st.pop();
        ans.push_back(top->data);
        if(top->right!=NULL)st.push(top->right);
        if(top->left!=NULL)st.push(top->left);
    }
    return ans;
}
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
void Inorder(TreeNode* root,vector<int> &ans){
    if(root==NULL)return;
    Inorder(root->left,ans);
    ans.push_back(root->data);
    Inorder(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    // Inorder(root,ans);
    stack<TreeNode*> st;
    TreeNode* node=root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty())break;
            node=st.top();
            st.pop();
            ans.push_back(node->data);
            node=node->right;
        }
    }
    return ans;
}
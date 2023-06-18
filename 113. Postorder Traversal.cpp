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
// void PostOrder(TreeNode* root,vector<int> &ans){
//     if(root==NULL)return;
//     PostOrder(root->left,ans);
//     PostOrder(root->right,ans);
//     ans.push_back(root->data);
// }
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root==NULL)return ans;
    // PostOrder(root,ans);
    // stack<TreeNode*> st1;
    // stack<TreeNode*> st2;
    // st1.push(root);
    // while(!st1.empty()){
    //     TreeNode* top=st1.top();
    //     st1.pop();
    //     st2.push(top);
    //     if(top->left)st1.push(top->left);
    //     if(top->right)st1.push(top->right);
    // }
    // while(!st2.empty()){
    //     TreeNode* node=st2.top();
    //     st2.pop();
    //     ans.push_back(node->data);
    // }
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(!st.empty() || curr!=NULL){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            TreeNode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else{
                curr=temp;
            }
        }
    }
    return ans;
}
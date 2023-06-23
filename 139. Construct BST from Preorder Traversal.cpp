#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* build(vector<int> &preOrder,int &i,int bound){
    if(i==preOrder.size()|| preOrder[i]>bound)return NULL;
    TreeNode<int>* root=new TreeNode<int>(preOrder[i++]);
    root->left=build(preOrder,i,root->data);
    root->right=build(preOrder,i,bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
   return build(preOrder,i,INT_MAX);
}
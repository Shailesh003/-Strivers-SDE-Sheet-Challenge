#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class Node{
    public:
    int maxsize;
    int minNode;
    int maxNode;
    Node(int minNode,int maxNode,int maxsize){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxsize=maxsize;
    }
};
Node largestBSThelper(TreeNode<int>* root){
    if(root==NULL)return Node(INT_MAX,INT_MIN,0);
    auto left=largestBSThelper(root->left);
    auto right=largestBSThelper(root->right);
    if(root->data>left.maxNode && root->data<right.minNode){
        return  Node(min(left.minNode,root->data),max(right.maxNode,root->data),left.maxsize+right.maxsize+1);
    }
    return Node(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
}
int largestBST(TreeNode<int>* root) 
{
   return largestBSThelper(root).maxsize;
}

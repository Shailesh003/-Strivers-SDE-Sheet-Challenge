#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
    void pushnext(BinaryTreeNode<int>* root,stack<BinaryTreeNode<int>*> &next){
        while(root){
            next.push(root);
            root=root->left;
        }
    }
    void pushbefore(BinaryTreeNode<int>* root,stack<BinaryTreeNode<int>*> &before){
        // if(root->right)root=root->right;
        while(root){
            before.push(root);
            root=root->right;
        }
    }

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
        if(root==NULL)return false;
        stack<BinaryTreeNode<int>*> next;
        stack<BinaryTreeNode<int>*> before;
        pushnext(root,next);
        pushbefore(root,before);
        // cout<<next.top()->data<<" "<<before.top()->data;
        while(!next.empty()&& !before.empty()){
            BinaryTreeNode<int>* min=next.top();
            BinaryTreeNode<int>* max=before.top();
            if(min->data==max->data)return false;
            // cout<<endl<<min->data<<" "<<max->data;
            if(min->data+max->data==k)return true;
            else if(min->data+max->data>k){
                before.pop();
                if(max->left)pushbefore(max->left,before);
            }
            else{
                next.pop();
                if(min->right)pushnext(min->right,next);
            }
        }
        return false;
}
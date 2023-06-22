#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    vector<vector<BinaryTreeNode< int >*>> levels;
    queue<BinaryTreeNode< int >*> q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<BinaryTreeNode< int >*> row;
        for(int i=0;i<size;i++){
            BinaryTreeNode< int >* node=q.front();
            q.pop();
            row.push_back(node);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        levels.push_back(row);
    }
    for(auto level:levels){
        for(int i=0;i<level.size()-1;i++){
            level[i]->next=level[i+1];
        }
        level.back()->next=NULL;
    }

}
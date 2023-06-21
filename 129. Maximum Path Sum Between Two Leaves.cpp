#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long Maximum(TreeNode<int>* root,long long int &maxi){
    if(root==NULL)return 0;
    long long int ls=max(0LL,Maximum(root->left,maxi));
    long long int rs=max(0LL,Maximum(root->right,maxi));
    maxi=max(maxi,root->val+ls+rs);
    return root->val+max(ls,rs);
}
long long int findMaxSumPath(TreeNode<int> *root)
{  if(root==NULL || root->left==NULL|| root->right==NULL)return -1;
   long long int maxi=INT_MIN;
   Maximum(root,maxi);
   return maxi;
}
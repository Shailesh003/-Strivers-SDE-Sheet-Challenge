/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int diameter(TreeNode<int>* root,int &ans){
    if(root==NULL)return 0;
    int lh=diameter(root->left,ans);
    int rh=diameter(root->right,ans);
    ans=max(ans,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int ans=0;
    diameter(root,ans);
    return ans;
}


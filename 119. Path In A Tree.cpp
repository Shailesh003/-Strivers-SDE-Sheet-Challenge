#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool Path(TreeNode<int> *root,int x,vector<int> &ans){
	if(root==NULL)return false;
	ans.push_back(root->data);
	if(root->data==x)return true;
	bool left=Path(root->left,x,ans);
	bool right=Path(root->right,x,ans);
	if(left || right)return true;
	ans.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	if(root==NULL)return ans;
	Path(root,x,ans);
	return ans;
}

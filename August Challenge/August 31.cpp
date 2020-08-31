/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * minValueNode(TreeNode * root)
    {
        TreeNode * current = root;
        while(current->left!=NULL)
            current=current->left;

        return current;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root)
		return root;

	if(key<root->val)
		root->left=deleteNode(root->left,key);
	else if(key>root->val)
		root->right=deleteNode(root->right,key);
	else
	{
		TreeNode * temp;
		if(root->left==NULL || root->right==NULL)
		{
			temp=root->left?root->left:root->right;

			if(!temp)
			{
				temp=root;
				root=NULL;
			}
			else
			{
				*root=*temp;
			}
			
		}
		else
		{
			temp=minValueNode(root->right);
			root->val=temp->val;
			root->right=deleteNode(root->right,temp->val);
		}
	}
    return root;
    }
};
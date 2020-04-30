/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode * root, int & result)
    {
        if(root==NULL)
            return 0;
        int leftheight=height(root->left,result);
        int rightheight=height(root->right,result);
        
        result=max(result,leftheight+rightheight+1);
        return max(leftheight,rightheight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int result=INT_MIN;
        int height_of_tree=height(root,result);
        return result-1;
    }
};
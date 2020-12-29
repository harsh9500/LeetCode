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
    int count;
    void preorder(TreeNode* root, int path)
    {
        if(root)
        {
            path^=(1<<root->val);
            if(!root->left && !root->right)
            {
                if((path & (path-1))==0)
                    count++;
            }
            preorder(root->left,path);
            preorder(root->right,path);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        count=0;
        preorder(root,0);
        return count;
    }
};
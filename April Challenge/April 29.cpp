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
    int maxPath(TreeNode * root, int & max_sum)
    {
        if(!root)
            return 0;
        
        int l=maxPath(root->left,max_sum);
        int r=maxPath(root->right,max_sum);
        
        int max_single=max(max(l,r)+root->val,root->val);
        int max_top=max(max_single,l+r+root->val);
        
        max_sum=max(max_sum,max_top);
        
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        int tmp=maxPath(root,max_sum);
        return max_sum;
    }
};
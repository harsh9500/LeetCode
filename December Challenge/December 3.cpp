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
    TreeNode* cur;
    void inorder(TreeNode* node)
    {
        if (node==NULL)
            return;
        inorder(node->left);
        node->left=NULL;
        cur->right=node;
        cur=node;
        inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        cur=ans;
        inorder(root);
        return ans->right;
    }
};
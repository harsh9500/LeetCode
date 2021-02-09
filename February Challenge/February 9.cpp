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
    int pre=0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return root;
        if (root->right)
            convertBST(root->right);
        pre = root->val = pre+root->val;
        if (root->left)
            convertBST(root->left);
        return root;
    }
};
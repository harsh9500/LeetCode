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
    vector<int> traversal;
    bool inorder(TreeNode* root)
    {
        if (!root)
            return true;
        
        if (!inorder(root->left)) 
            return false;
        
        if (traversal.size()>0 && root->val <= traversal.back())
            return false;
        
        traversal.push_back(root->val);
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        traversal.clear();
        return inorder(root);
    }
};
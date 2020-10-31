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
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    TreeNode* prevElement = new TreeNode(INT_MIN);
    
    void traverse(TreeNode * root)
    {
        if(root==NULL)
            return;
        traverse(root->left);
        if(firstElement==NULL && prevElement->val>root->val)
            firstElement=prevElement;
        if(firstElement!=NULL && prevElement->val>root->val)
            secondElement=root;
        prevElement=root;
        traverse(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(firstElement->val,secondElement->val);
    }
};
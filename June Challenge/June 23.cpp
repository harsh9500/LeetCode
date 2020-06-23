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
    int height(TreeNode * root)
    {
        if(root==nullptr)
            return -1;
        return 1+height(root->left);
    }
    int countNodes(TreeNode* root) {
        int nodes=0;
        int h=height(root);
        while(root!=nullptr)
        {
            if(height(root->right)==h-1)
            {
                nodes+=1<<h;
                root=root->right;
            }
            else
            {
                nodes+=1<<h-1;
                root=root->left;
            }
            h--;
        }
        return nodes;
    }
};
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode *,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p.first->left==NULL && p.first->right==NULL)
                return p.second;
            if(p.first->left!=NULL)
            {
                q.push(make_pair(p.first->left,p.second+1));
            }
            if(p.first->right!=NULL)
            {
                q.push(make_pair(p.first->right,p.second+1));
            }
        }
        return 0;
    }
};
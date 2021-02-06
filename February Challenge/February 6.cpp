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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel=1, nextLevel=0;
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t->left)
            {
                q.push(t->left);
                nextLevel++;
            }
            if(t->right)
            {
                q.push(t->right);
                nextLevel++;
            }
            currentLevel--;
            if(currentLevel==0)
            {
                v.push_back(t->val);
                currentLevel=nextLevel;
                nextLevel=0;
            }
        }
        return v;
    }
};
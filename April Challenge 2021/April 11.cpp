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
    int deepestLeavesSum(TreeNode* root) {
        int answer=0, i;
        if(!root)
            return answer;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            for(i=q.size()-1,answer=0;i>=0;i--)
            {
                TreeNode* temp = q.front();
                q.pop();
                answer+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                
            }
        }
        return answer;
    }
};
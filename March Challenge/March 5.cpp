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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        if(!root)
            return answer;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel=1;
        int nodes=0;
        double sum=0;
        int nextLevel=0;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            sum+=curr->val;
            currentLevel--;
            nodes++;
            if(curr->left)
            {
                q.push(curr->left);
                nextLevel++;
            }
            if(curr->right)
            {
                q.push(curr->right);
                nextLevel++;
            }
            if(currentLevel==0)
            {
                answer.push_back(sum/double(nodes));
                nodes=0;
                sum=0;
                currentLevel=nextLevel;
                nextLevel=0;
            }
        }
        return answer;
    }
};
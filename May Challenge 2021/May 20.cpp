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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if(!root)
            return answer;
        int currentLevel = 1, nextLevel = 0;
        queue<TreeNode* > q;
        q.push(root);
        vector<int> temp;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            currentLevel--;
            temp.push_back(node->val);
            if(node->left)
            {
                q.push(node->left);
                nextLevel++;
            }
            if(node->right)
            {
                q.push(node->right);
                nextLevel++;
            }
            if(currentLevel==0)
            {
                answer.push_back(temp);
                temp.clear();
                currentLevel=nextLevel;
                nextLevel=0;
            }
        }
        return answer;
    }
};
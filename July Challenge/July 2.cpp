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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL)
            return answer;
        vector<int> temp;
        queue<TreeNode *> q;
        q.push(root);
        int currentLevelNodes=1,nextLevelNodes=0;
        while(!q.empty())
        {
            TreeNode * current=q.front();
            q.pop();
            temp.push_back(current->val);
            if(current->left!=NULL)
            {
                q.push(current->left);
                nextLevelNodes++;
            }
            if(current->right!=NULL)
            {
                q.push(current->right);
                nextLevelNodes++;
            }
            currentLevelNodes--;
            if(currentLevelNodes==0)
            {
                currentLevelNodes=nextLevelNodes;
                nextLevelNodes=0;
                answer.push_back(temp);
                temp.clear();
            }
            
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
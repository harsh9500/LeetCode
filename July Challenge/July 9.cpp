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
    int widthOfBinaryTree(TreeNode* root) {
        int answer=0;
        if(root==NULL)
            return 0;
        queue<TreeNode *> q;
        unordered_map<TreeNode*,unsigned long long int> m;
        q.push(root);
        m[root]=1;
        int size,start,end;
        while(!q.empty())
        {
            size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode * current=q.front();
                q.pop();
                if(i==0)
                    start=m[current];
                if(i==size-1)
                    end=m[current];
                if(current->left!=NULL)
                {
                    q.push(current->left);
                    m[current->left]=m[current]*2;
                }
                if(current->right!=NULL)
                {
                    q.push(current->right);
                    m[current->right]=m[current]*2+1;
                }
            }
            answer=max(answer,end-start+1);
        }
        
        return answer;
    }
};
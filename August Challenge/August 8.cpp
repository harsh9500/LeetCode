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
    int dfs(TreeNode * root, int sum, int currSum, unordered_map<int,int> & m)
    {
        if(!root)
            return 0;
        int rootToCurrent=currSum+root->val;
        int paths=m[rootToCurrent-sum];
        if(rootToCurrent==sum)
            paths++;
        m[rootToCurrent]++;
        int left=dfs(root->left,sum,rootToCurrent,m);
        int right=dfs(root->right,sum,rootToCurrent,m);
        m[rootToCurrent]--;
        return paths+left+right;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int,int> m;
        return dfs(root,sum,0,m);
    }
};
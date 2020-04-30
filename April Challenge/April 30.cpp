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
    int n;
    bool dfs(TreeNode* node, int index, vector<int> arr)
    {
        if(node==NULL)
            return false;
        if(node->val!=arr[index])
            return false;
        if(index==n-1)
        {
            if(node->left==nullptr && node->right==nullptr)
                return true;
            return false;
        }
        return dfs(node->left,index+1,arr) || dfs(node->right,index+1,arr);
        
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n=arr.size();
        if(dfs(root,0,arr))
            return true;
        return false;
    }
};
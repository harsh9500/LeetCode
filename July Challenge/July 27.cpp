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
unordered_map<int,int> m;
public:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end, int * index)
    {
        if(start>end)
            return NULL;
        
        TreeNode* node=new TreeNode(postorder[*index]);
        (*index)--;
        
        if(start==end)
            return node;
        
        int currIndex=m[node->val];
        node->right=build(inorder,postorder,currIndex+1,end,index);
        node->left=build(inorder,postorder,start,currIndex-1,index);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        m.clear();
        int n=inorder.size();
        TreeNode * root=NULL;
        if(n==0)
            return root;
        for(int i=0;i<n;i++)
            m[inorder[i]]=i;
        int index=n-1;
        root=build(inorder,postorder,0,n-1,&index);
        return root;
    }
};
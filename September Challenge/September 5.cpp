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
    void inorder(TreeNode * root, vector<int> & list)
    {
        if(root)
        {
            inorder(root->left,list);
            list.push_back(root->val);
            inorder(root->right,list);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2,l3;
        inorder(root1,l1);
        inorder(root2,l2);
        int i=0,j=0,n=l1.size(),m=l2.size();
        while(i<n && j<m)
        {
            if(l1[i]<l2[j])
                l3.push_back(l1[i++]);
            else
                l3.push_back(l2[j++]);
        }
        while(i<n)
        {
            l3.push_back(l1[i++]);
        }
        while(j<m)
        {
            l3.push_back(l2[j++]);
        }
        return l3;
    }
};
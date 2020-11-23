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
    unordered_map<TreeNode*, int> robbed;
    unordered_map<TreeNode*, int> notRobbed;
    int money(TreeNode* node, bool parentRobbed)
    {
        if(!node)
            return 0;
        int result=0;
        if(parentRobbed)
        {
            if(robbed.find(node)!=robbed.end())
                return robbed[node];
            result=money(node->left,false)+money(node->right,false);
            robbed[node]=result;
        }
        else
        {
            if(notRobbed.find(node)!=robbed.end())
                return notRobbed[node];
            int rob=node->val+money(node->left,true)+money(node->right,true);
            int notRob=money(node->left,false)+money(node->right,false);
            result=max(rob,notRob);
            notRobbed[node]=result;    
        }
        return result;
    }
    int rob(TreeNode* root) {
        robbed.clear();
        notRobbed.clear();
        return money(root,false);
    }
};
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
    // void verticalOrderTraversal(TreeNode * root, int hd, map<int,vector<int>> & m)
    // {
    //     if(root==NULL)
    //         return;
    //     m[hd].push_back(root->val);
    //     verticalOrderTraversal(root->left,hd-1,m);
    //     verticalOrderTraversal(root->right,hd+1,m);
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;
        if(root==NULL)
            return answer;
        map<int,vector<int>> m;
        int hd=0;
        int minLevel=0,maxLevel=0;
        map<int,vector<int>> tempMap;
        queue<pair<TreeNode *, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            tempMap.clear();
            for(int i=0;i<size;i++)
            {
                pair<TreeNode *, int> temp=q.front();
                q.pop();
                tempMap[temp.second].push_back(temp.first->val);
                minLevel=min(minLevel,temp.second);
                maxLevel=max(maxLevel,temp.second);
                if(temp.first->left!=NULL)
                {
                    q.push({temp.first->left,(temp.second)-1});
                }
                if(temp.first->right!=NULL)
                {
                    q.push({temp.first->right,(temp.second)+1});
                }
            }
            
            for(auto it=tempMap.begin();it!=tempMap.end();it++)
            {
                sort((it->second).begin(),(it->second).end());
                for(auto ele:it->second)
                {
                    m[it->first].push_back(ele);
                }    
            }
            
        }
        
        for (int i=minLevel; i<=maxLevel; i++)
        {
            answer.push_back(m[i]);
        }
        return answer;
    }
};
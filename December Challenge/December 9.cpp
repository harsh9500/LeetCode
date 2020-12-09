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
class BSTIterator {
public:
    deque<TreeNode*> dq;
    void leftinorder(TreeNode* root)
    {
        while(root!=NULL)
        {
            dq.push_back(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        dq.clear();
        leftinorder(root);
    }
    
    int next() {
        TreeNode* t=dq.back();
        dq.pop_back();
        
        if(t->right!=NULL)
        {
            leftinorder(t->right);
        }
        return t->val;
    }
    
    bool hasNext() {
        return dq.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
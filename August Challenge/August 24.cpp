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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
			return 0;
        
		queue<TreeNode*> nodeQueue;
		nodeQueue.push(root);
	
		int leftLeavesSum = 0;
		TreeNode* currNode;
		while (!nodeQueue.empty()) {
			currNode = nodeQueue.front();
			nodeQueue.pop();
			
			if (currNode->left)
            {
				if (!currNode->left->left && !currNode->left->right)
                { 
					leftLeavesSum += currNode->left->val;
				}
				else 
                {
					nodeQueue.push(currNode->left);
				}
			}
			
			if (currNode->right)
				nodeQueue.push(currNode->right);
		}
		return leftLeavesSum;
    }
};
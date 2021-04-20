/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> answer;
    vector<int> preorder(Node* root) {
        if(!root)
            return answer;
        
        // answer.push_back(root->val);
        // for(auto node:root->children)
        // {
        //     preorder(node);
        // }       
        
        stack<Node*> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            answer.push_back(root->val);
            for (int i=root->children.size()-1; i>=0; i--)
                st.push(root->children[i]);
        }
        
        return answer;
    }
};
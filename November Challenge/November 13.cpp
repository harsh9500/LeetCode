/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        int currentCount=1,nextCount=0,flag=1;
        Node * curr, *prev;
        while(!q.empty())
        {
            curr=q.front();
            currentCount--;
            q.pop();
            if(nextCount==0 && flag)
            {
                flag=0;
            }
            else
            {
                prev->next=curr;
            }
            prev=curr;
            if(curr->left)
            {
                q.push(curr->left);
                nextCount++;
            }
            if(curr->right)
            {
                q.push(curr->right);
                nextCount++;
            }
            if(currentCount==0)
            {
                curr->next=NULL;
                currentCount=nextCount;
                nextCount=0;
                flag=1;
            }
        }
        return root;
    }
};
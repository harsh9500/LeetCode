/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node, vector<Node*>& cloned) {
        
    auto clone = new Node(node->val);
    cloned[node->val - 1] = clone;
	
    for (auto adj : node->neighbors)
    {
        if (Node* adj_clone = cloned[adj->val - 1])
        {
            clone->neighbors.push_back(adj_clone);
        }
        else
        {
            clone->neighbors.push_back(cloneGraph(adj, cloned));
        }
    }
    return clone;
  }
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;
    
        vector<Node*> cloned(100);
        return cloneGraph(node, cloned);
    }
};
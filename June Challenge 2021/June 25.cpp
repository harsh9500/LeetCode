class Solution {
public:
    int find(int parent[], int f) {
        if (f != parent[f]) {
          parent[f] = find(parent, parent[f]);  
        }
        return parent[f];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int parent[2001];
        for (int i = 0; i < 2001; i++)
            parent[i] = i;
        
        for (auto edge: edges)
        {
            int f = edge[0], t = edge[1];
            if (find(parent, f) == find(parent, t))
                return edge;
            else parent[find(parent, f)] = find(parent, t);
        }
        
        return vector<int>();
    }
};
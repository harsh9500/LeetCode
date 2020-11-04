class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<2)
        {
            vector<int> answer;
            for(int i=0;i<n;i++)
                answer.push_back(i);
            return answer;
        }
        vector<vector<int>> adj(n,vector<int>(0));
        for(int i=0;i<n-1;i++)
        {
            int start=edges[i][0];
            int end=edges[i][1];
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()==1)
                leaves.push_back(i);
        }
        int remaining=n;
        while(remaining>2)
        {
            remaining-=leaves.size();
            vector<int> newLeaves;
            for(auto leaf:leaves)
            {
                for(auto node:adj[leaf])
                {
                    adj[node].erase(find(adj[node].begin(),adj[node].end(),leaf));
                    if(adj[node].size()==1)
                        newLeaves.push_back(node);
                }
            }
            leaves=newLeaves;
        }
        
        return leaves;
    }
};
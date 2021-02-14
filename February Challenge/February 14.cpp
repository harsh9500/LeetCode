class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i])
                continue;
            color[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int cur=q.front();
                q.pop();
                for(int neighbour:graph[cur])
                {
                    if(!color[neighbour])
                    {
                        color[neighbour]=-color[cur];
                        q.push(neighbour);
                    }
                    else if(color[neighbour]==color[cur])
                        return false;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    void dfs(vector<vector<int>> graph, vector<vector<int>> & answer, vector<int> & temp, int i, int n)
    {
        temp.push_back(i);
        if(i==n)
        {
            answer.push_back(temp);
        }
        else
        {
            for(int j=0;j<graph[i].size();j++)
                dfs(graph,answer,temp,graph[i][j],n);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answer;
        int n=graph.size();
        if(n==0)
            return answer;
        vector<int> temp;
        dfs(graph,answer,temp,0,n-1);
        return answer;
    }
};
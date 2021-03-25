class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions {{0,1},{1,0},{0,-1},{-1,0}};    
    vector<vector<bool>> bfs(vector<vector<int>>& matrix, queue<vector<int>> ocean)
    {
        vector<vector<bool>> reach(rows,vector<bool>(cols,false));

        while(!ocean.empty())
        {
            vector<int> temp=ocean.front();
            ocean.pop();
            reach[temp[0]][temp[1]]=true;
            for(auto v:directions)
            {
                int x=temp[0]+v[0];
                int y=temp[1]+v[1];
                if(x<0 || y<0 || x>=rows || y>=cols)
                    continue;
                if(reach[x][y])
                    continue;
                if(matrix[x][y]<matrix[temp[0]][temp[1]])
                    continue;
                ocean.push({x,y});
            }
        }
        return reach;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> answer;
        rows=matrix.size();
        if(rows==0)
            return answer;
        cols=matrix[0].size();
        if(cols==0)
            return answer;
        queue<vector<int>> pacificQ;
        queue<vector<int>> atlanticQ;
        for(int i=0;i<rows;i++)
        {
            pacificQ.push(vector<int> {i,0});
            atlanticQ.push(vector<int> {i,cols-1});
        }
        for(int i=0;i<cols;i++)
        {
            pacificQ.push(vector<int> {0,i});
            atlanticQ.push(vector<int> {rows-1,i});
        }
        vector<vector<bool>> pacific=bfs(matrix,pacificQ);
        vector<vector<bool>> atlantic=bfs(matrix,atlanticQ);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    answer.push_back({i,j});
                }
            }
        }
        return answer;
    }
};
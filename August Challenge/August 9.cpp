class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size();
        if(n==0)
            return count;
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else
                    if(grid[i][j]==1)
                        count++;
            }
        }
        if(count==0)
            return count;
        int answer=0;
        vector<pair<int,int>> v{{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            answer++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> temp=q.front();
                q.pop();
                for(auto direction:v)
                {
                    int x=temp.first+direction.first;
                    int y=temp.second+direction.second;
                    if(x<0 || y<0 || x>=n || y>=m || grid[x][y]==2 || grid[x][y]==0)
                        continue;
                    grid[x][y]=2;
                    q.push({x,y});
                    count--;
                }
            }
        }
        if(count==0)
            return answer-1;
        return -1;
        
    }
};
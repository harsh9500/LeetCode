class Solution {
public:
    int answer;
    int row_offsets[4]={0,0,1,-1};
    int col_offsets[4]={1,-1,0,0};
    void backtrack(vector<vector<int>>& grid, int i, int j, int remaining)
    {
        if(grid[i][j]==2 && remaining==1)
        {
            answer++;
            return;
        }
        int currValue=grid[i][j];
        grid[i][j]=-10;
        remaining--;
        
        for(int it=0;it<4;it++)
        {
            int nextrow=i+row_offsets[it];
            int nextcol=j+col_offsets[it];
            if(nextrow<0 || nextrow>=grid.size() || nextcol<0 || nextcol>=grid[0].size())
                continue;
            if(grid[nextrow][nextcol]<0)
                continue;
            backtrack(grid,nextrow,nextcol,remaining);
        }
        grid[i][j]=currValue;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int start_row,start_col,non_obstacles=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=-1)
                    non_obstacles++;
                if(grid[i][j]==1)
                {
                    start_row=i;
                    start_col=j;
                }
            }
        }
        answer=0;
        backtrack(grid,start_row,start_col,non_obstacles);
        return answer;
    }
};
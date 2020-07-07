class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer=0;
        int n=grid.size();
        if(n==0)
            return answer;
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    answer+=4;
                    if(i>0 && grid[i-1][j]==1)
                    {
                        answer--;
                    }
                    if(i<n-1 && grid[i+1][j]==1)
                    {
                        answer--;
                    }
                    if(j>0 && grid[i][j-1]==1)
                    {
                        answer--;
                    }
                    if(j<m-1 && grid[i][j+1]==1)
                    {
                        answer--;
                    }
                }
            }
        }
        return answer;
        
    }
};
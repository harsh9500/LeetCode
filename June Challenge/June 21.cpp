class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                    dungeon[i][j]=max(1,1-dungeon[i][j]);
                else
                {
                    if(i==n-1)
                        dungeon[i][j]=max(1,dungeon[i][j+1]-dungeon[i][j]);
                    else
                    {
                        if(j==m-1)
                            dungeon[i][j]=max(1,dungeon[i+1][j]-dungeon[i][j]);
                        else
                            dungeon[i][j]=max(1,min(dungeon[i+1][j],dungeon[i][j+1])-dungeon[i][j]);
                    }
                }
            }
        }
        return dungeon[0][0];
    }
};
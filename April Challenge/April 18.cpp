class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<n;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
        
    }
};
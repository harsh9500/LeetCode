class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n+1;i++)
        {
            if(dp[i])
                continue;
            for(int j=1;i+j*j<=n;j++)
            {
                dp[i+j*j]=true;
            }
        }
        return dp[n];
    }
};
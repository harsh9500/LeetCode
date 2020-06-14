class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K+2,vector<int>(n,INT_MAX));
        //dp[i][j] = Dist to reach j using atmost i edges from src
        int a,b,c;
        for(int i=0;i<=K+1;i++)
        {
            dp[i][src]=0;
        }
        for(int i=1;i<=K+1;i++)
        {
            for(auto f:flights)
            {
                a=f[0];
                b=f[1];
                c=f[2];
                if(dp[i-1][a]!=INT_MAX)
                {
                    dp[i][b]=min(dp[i][b],dp[i-1][a]+c);
                }
            }
        }
        if(dp[K+1][dst]==INT_MAX)
            return -1;
        return dp[K+1][dst];
    }
};
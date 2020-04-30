class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            dp[i][0]=matrix[i][0]-'0';
        for(int i=0;i<m;i++)
            dp[0][i]=matrix[0][i]-'0';
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
                if((matrix[i][j]-'0')==1)
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
        }
        int answer=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j]>answer)
                    answer=dp[i][j];
            }
        }
        return answer*answer;
    }
};
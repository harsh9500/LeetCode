class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[k + 1];
        memset(dp,0,sizeof(dp));
        int M = 1000000007;
        for (int i = 1; i <= n; i++)
        {
            int temp[k + 1];
            temp[0] = 1;
            for (int j = 1; j <= k ; j++)
            {
                int val = (dp[j] + M - ((j - i) >= 0 ? dp[j - i] : 0)) % M;
                temp[j] = (temp[j - 1] + val) % M;
            }
            for(int i = 0; i <= k; i++)
                dp[i] = temp[i];
        }
        return ((dp[k] + M - (k > 0 ? dp[k - 1] : 0)) % M);
    }
};
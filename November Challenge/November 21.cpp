class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string S=to_string(n);
        int K=S.length();
        int dp[K+1];
        memset(dp,0,sizeof(dp));
        dp[K]=1;
        int len=digits.size();
        for (int i=K-1;i>=0;i--)
        {
            int Si=S[i]-'0';
            for (string d:digits)
            {
                if (d[0]-'0'<Si)
                    dp[i]+=pow(len,K-i-1);
                else if (d[0]-'0'==Si)
                    dp[i]+=dp[i+1];
            }
        }
        for (int i=1;i<K;i++)
            dp[0]+=pow(len,i);
        return dp[0];
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word2.length() + 1];
        memset(dp,0,sizeof(dp));
        for (int i = 0; i <= word1.length(); i++)
        {
            int temp[word2.length() + 1];
            for (int j = 0; j <= word2.length(); j++)
            {
                if (i == 0 || j == 0)
                    temp[j] = i + j;
                else if (word1[i - 1] == word2[j - 1])
                    temp[j] = dp[j - 1];
                else
                    temp[j] = 1 + min(dp[j], temp[j - 1]);
            }
            for(int i=0;i<word2.length()+1;i++)
                dp[i]=temp[i];
        }
        return dp[word2.length()];
    }
};
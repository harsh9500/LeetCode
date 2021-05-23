class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> dp(1<<n,vector<string>(n));
        vector<vector<int>> overlap(n,vector<int>(n,0));
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(i!=j)
                {
                    for(int k = min(words[i].size(), words[j].size()); k>0; --k)
                        if(words[i].substr(words[i].size()-k)==words[j].substr(0,k))
                        {
                            overlap[i][j] = k; 
                            break;
                        }
                }
        
        for(int i=0; i<n; ++i)
            dp[1<<i][i] += words[i];
        
        for(int mask=1; mask<(1<<n); ++mask)
        {
            for(int j=0; j<n; ++j)
                if((mask&(1<<j))>0)
                {
                    for(int i=0; i<n; ++i)
                        if(i!=j && (mask&(1<<i))>0)
                        {
                            string tmp = dp[mask^(1<<j)][i]+words[j].substr(overlap[i][j]);
                            if(dp[mask][j].empty() || tmp.size()<dp[mask][j].size())
                                dp[mask][j] = tmp;
                        }
                }
        }
        
        int last = (1<<n)-1;
        string res = dp[last][0];
        for(int i=1; i<n; ++i)
            if(dp[last][i].size()<res.size())
            {
                res = dp[last][i];
            }
        return res;
    }
};
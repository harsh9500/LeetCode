class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto st:wordDict)
            set.insert(st);
        int n=s.length();
        bool wb[n+1];
        memset(wb,false,sizeof(wb));
        for(int i=1;i<=n;i++)
        {
            string prefix=s.substr(0,i);
            if(wb[i]==false && set.find(prefix)!=set.end())
                wb[i]=true;
            if(wb[i])
            {
                if(i==n)
                    return true;
                for(int j=i+1;j<=n;j++)
                {
                    if(wb[j]==false && set.find(s.substr(i,j-i))!=set.end())
                        wb[j]=true;
                    if(j==n && wb[j]==true)
                        return true;
                }
            }
        }
        return false;
    }
};
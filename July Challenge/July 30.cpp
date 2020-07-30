class Solution {
public:
    bool isPossible(string s, unordered_set<string> set)
    {
        int n=s.length();
        if(n==0)
            return true;
        bool arr[n+1];
        memset(arr,false,sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            string str=s.substr(0,i);
            if(arr[i]==false && set.find(str)!=set.end())
                arr[i]=true;
            if(arr[i]==true)
            {
                if(i==n)
                    return true;
                for(int j=i+1;j<=n;j++)
                {
                    if(arr[j]==false && set.find(s.substr(i,j-i))!=set.end())
                        arr[j]=true;
                    if(j==n && arr[j]==true)
                        return true;
                }
            }
        }
        return false;
    }
    void wordBreak(string s, unordered_set<string> set, vector<string> & answer,string current)
    {
        int n=s.length();
        for(int i=1;i<=n;i++)
        {
            string prefix=s.substr(0,i);
            if(set.find(prefix)!=set.end())
            {
                if(i==n)
                {
                    current+=prefix;
                    answer.emplace_back(current);
                    return;
                }
                wordBreak(s.substr(i,n-i),set,answer,current+prefix+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto st:wordDict)
            set.insert(st);
        vector<string> answer;
        if(!isPossible(s,set))
            return answer;
        wordBreak(s,set,answer,"");
        return answer;
    }
};
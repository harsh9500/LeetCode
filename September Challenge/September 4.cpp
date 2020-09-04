class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        memset(last,0,sizeof(last));
        for (int i=0;i<S.length();i++)
            last[S[i]-'a']=i;
        
        int j=0, anchor=0;
        vector<int> ans;
        for (int i=0;i<S.length();i++)
        {
            j=max(j,last[S[i]-'a']);
            if (i==j)
            {
                ans.push_back(i-anchor+1);
                anchor=i+1;
            }
        }
        return ans;
    }
};
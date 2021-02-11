class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length(), m=t.length();
        if(n!=m)
            return false;
        int scount[26];
        int tcount[26];
        memset(scount,0,sizeof(scount));
        memset(tcount,0,sizeof(tcount));
        for(int i=0;i<n;i++)
        {
            scount[s[i]-'a']++;
            tcount[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(scount[i]!=tcount[i])
                return false;
        }
        return true;
    }
};
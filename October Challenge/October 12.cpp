class Solution {
public:
    bool buddyStrings(string A, string B) {
        int n=A.length();
        int m=B.length();
        if(n!=m)
            return false;
        if (A.compare(B)==0)
        {
            int count[26]={};
            for (int i=0;i<n;i++)
                count[A[i]-'a']++;
            for (int c:count)
                if (c>1)
                    return true;
            return false;
        }
        else
        {
            int first=-1,second=-1;
            for (int i=0;i<n;i++)
            {
                if (A[i]!= B[i])
                {
                    if (first==-1)
                        first=i;
                    else
                        if(second==-1)
                        second = i;
                    else
                        return false;
                }
            }
            return (second!=-1 && A[first]==B[second] && A[second]==B[first]);
        }
    }
};
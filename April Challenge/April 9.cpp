class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i=S.length()-1,j=T.length()-1;
        int s=0, t=0;
        
        while(i>=0 || j>=0)
        {
            while(i>=0)
            {
                if(S[i]=='#')
                {
                    s++;
                    i--;
                }
                else
                {
                    if(s>0)
                    {
                        s--;
                        i--;
                    }
                    else
                        break;
                }
            }
            while(j>=0)
            {
                if(T[j]=='#')
                {
                    t++;
                    j--;
                }
                else
                {
                    if(t>0)
                    {
                        t--;
                        j--;
                    }
                    else
                        break;
                }
            }
            if(i>=0 && j>=0 && S[i]!=T[j])
                return false;
            if((i>=0) != (j>=0))
                return false;
            i--;
            j--;
        }
        return true;
    }
};
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balanced=0;
        int n=s.length();
        string answer="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                balanced++;
                answer+=s[i];
            }
            else
            {
                if(s[i]==')')
                {
                    if(balanced>0)
                    {
                        answer+=s[i];
                        balanced--;
                    }
                }
                else
                    answer+=s[i];
            }
        }
        n=answer.length();
        string finals="";
        balanced=0;
        for(int i=n-1;i>=0;i--)
        {
            if(answer[i]==')')
            {
                balanced++;
                finals+=answer[i];
            }
            else
            {
                if(answer[i]=='(')
                {
                    if(balanced>0)
                    {
                        finals+=answer[i];
                        balanced--;
                    }
                }
                else
                    finals+=answer[i];
            }
        }
        reverse(finals.begin(),finals.end());
        return finals;
    }
};
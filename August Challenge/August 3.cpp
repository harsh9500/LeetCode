class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return true;
        string str="";
        for(int i=0;i<n;i++)
        {
            if(isalpha(s[i]))
            {
                // if(isupper(s[i]))
                //     s[i]=tolower(s[i]);
                str+=tolower(s[i]);
            }
            if(isdigit(s[i]))
                str+=s[i];
        }
        n=str.length();
        int i=0,j=n-1;
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
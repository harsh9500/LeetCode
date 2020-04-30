class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                low++;
            else
                low--;
            if(s[i]!=')')
                high++;
            else
                high--;
            if(high<0)
                break;
            low=max(low,0);
        }
        return low==0;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        char result;
        int n=s.length();
        int m=t.length();
        int xor_value=0;
        for(int i=0;i<n;i++)
        {
            xor_value^=s[i]-'a';
        }
        for(int i=0;i<m;i++)
        {
            xor_value^=t[i]-'a';
        }
        return char(xor_value+'a');
    }
};
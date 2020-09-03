class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        string s2=s+s;
        s2=s2.substr(1,2*n-2);
        if(s2.find(s)!=string::npos)
            return true;
        return false;
    }
};
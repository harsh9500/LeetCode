class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0)
            return 0;
        if(s==string(s.rbegin(),s.rend()))
            return 1;
        return 2;
    }
};
class Solution {
public:
    int titleToNumber(string s) {
        int n=s.length();
        if(n==1)
            return s[0]-'A'+1;
        int answer=0;
        for(int i=n-1;i>=0;i--)
        {
            answer+=((s[i]-'A'+1)*pow(26,n-i-1));
        }
        return answer;
    }
};
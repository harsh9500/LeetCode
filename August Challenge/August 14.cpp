class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        int n=s.length();
        for(int i=0;i<n;i++)
            m[s[i]]++;
        int answer=0;
        int maxOdd=0;
        int flag=0;
        for(auto it:m)
        {
            if((it.second)%2==0)
                answer+=it.second;
            else
            {
                answer+=it.second-1;
                flag=1;
            }
        }
        answer+=flag;
        return answer;
    }
};
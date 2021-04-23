class Solution {
public:
    int countBinarySubstrings(string s) {
        int answer=0, prev=0, cur=1;
        int n=s.length();
        for(int i=1;i<n;i++)
        {
            if(s[i-1]!=s[i])
            {
                answer+=min(prev,cur);
                prev=cur;
                cur=1;
            }
            else
                cur++;
        }
        answer+=min(prev,cur);
        return answer;
    }
};
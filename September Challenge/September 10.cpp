class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        int i=0,j=0,bulls=0,cows=0;
        int digits1[10];
        int digits2[10];
        memset(digits1,0,sizeof(digits1));
        memset(digits2,0,sizeof(digits2));
        while(i<n)
        {
            if(secret[i]==guess[i])
                bulls++;
            digits1[secret[i]-'0']++;
            digits2[guess[i]-'0']++;
            i++;
            j++;
        }
        for(int i=0;i<10;i++)
        {
            cows+=min(digits1[i],digits2[i]);
        }
        cows-=bulls;
        string answer=to_string(bulls)+"A";
        answer+=to_string(cows)+"B";
        return answer;
    }
};
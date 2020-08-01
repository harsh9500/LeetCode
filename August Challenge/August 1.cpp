class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag=0;
        int n=word.length();
        if(islower(word[0]))
            flag=1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(islower(word[i]))
                count++;
        }
        if(count==n || count==0)
            return true;
        if(flag==0 && count==n-1)
            return true;
        return false;
            
    }
};
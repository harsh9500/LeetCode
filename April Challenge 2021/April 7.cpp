class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
          || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n/2;i++)
        {
            if(isVowel(s[i]))
                count++;
        }
        for(int i=n/2;i<n;i++)
        {
            if(isVowel(s[i]))
                count--;
        }
        return count == 0;
    }
};
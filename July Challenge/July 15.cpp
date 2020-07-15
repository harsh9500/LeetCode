class Solution {
public:
    string reverse(string str, int i, int j)
    {
        char temp;
        while(i<j)
        {
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            i++;
            j--;
        }
        return str;
    }
    string reverseWords(string s) {
        string chars = "\t\n\v\f\r ";
        s.erase(s.find_last_not_of(chars) + 1);
        s.erase(0, s.find_first_not_of(chars));
        int i=0,n=s.length();
        s=reverse(s,0,n-1);
        string answer="",temp="";
        while(i<n)
        {
            while(i<n && s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            temp=reverse(temp,0,temp.length()-1);
            answer+=temp;            
            temp="";
            while(i<n && s[i]==' ')
            {
                i++;
            }
            if(i<n)
                answer+=" ";
        }
        return answer;
    }
};
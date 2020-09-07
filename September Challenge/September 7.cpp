class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream stream (str);
        string temp;
        int n=pattern.length();
        int i=0,count=0;;
        unordered_map<char,string> m;
        unordered_map<string,char> rev_m;
        while(getline(stream,temp,' '))
        {
            if(i==n)
                return false;
            if(m.find(pattern[i])!=m.end() && m[pattern[i]]!=temp)
                return false;
            if(rev_m.find(temp)!=rev_m.end() && rev_m[temp]!=pattern[i])
                return false;
            m[pattern[i]]=temp;
            rev_m[temp]=pattern[i];
            i++;
            count++;
        }
        if(i==n && i==count)
            return true;
        return false;
    }
};
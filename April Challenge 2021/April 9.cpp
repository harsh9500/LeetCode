class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int m[26];
        for(int i=0;i<26;i++)
        {
            m[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(j>=words[i+1].length())
                    return false;
                if(words[i][j] != words[i+1][j])
                {
                    if(m[words[i][j]-'a'] > m[words[i+1][j]-'a'])
                        return false;
                    else
                        break;
                }
            }
        }
        return true;
    }
};
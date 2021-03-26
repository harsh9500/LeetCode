class Solution {
public:
    vector<int> count(string s) {
        vector<int> c(26,0);
        for(auto ch:s)
        {
            c[ch-'a']++;
        }
        return c;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> answer;
        vector<int> bMax = count("");
        for(string b:B)
        {
            vector<int> temp = count(b);
            for(int i=0;i<26;i++)
            {
                bMax[i]=max(bMax[i],temp[i]);
            }
        }
        bool flag;
        for(string a:A)
        {
            flag=true;
            vector<int> temp = count(a);
            for(int i=0;i<26;i++)
            {
                if(temp[i]<bMax[i])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                answer.push_back(a);
            }
        }
        return answer;
    }
};
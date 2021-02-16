class Solution {
public:
    void backtrack(string &s, int i, vector<string> &res)
    {
        if (i==s.size())
        {
            res.push_back(s);
            return;
        }
        backtrack(s,i+1,res);
        if (isalpha(s[i]))
        {
            s[i]^=(1 << 5);
            backtrack(s,i+1,res);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S,0,res);
        return res;
    }
};
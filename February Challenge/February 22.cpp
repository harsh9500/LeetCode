class Solution {
public:
    bool isSubsequence(string x, string y)
    {
        int j=0;
        for (int i=0; i<y.length() && j<x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j==x.length();
    }
    string findLongestWord(string s, vector<string>& d) {
        string max_str="";
        for (string str:d)
        {
            if (isSubsequence(str,s))
            {
                if (str.length() > max_str.length() || (str.length() == max_str.length() && str.compare(max_str) < 0))
                    max_str = str;
            }
        }
        return max_str;
    }
};
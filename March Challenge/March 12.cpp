class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=1<<k;
        unordered_set<string> got;
        
        for (int i=0;i<s.length();i++)
        {
            string a=s.substr(i,k);
            if (a.length()==k && got.find(a)==got.end())
            {
                got.insert(a);
                need--;
                if (need==0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
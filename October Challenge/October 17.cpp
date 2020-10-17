class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, bool> m;
        vector<string> r;
        for (long long int t = 0, i = 0; i < s.size(); i++)
        {
            t = t << 3 & 0x3FFFFFFF | s[i] & 7;
            if (m.find(t) != m.end())
            {
                if (m[t])
                {
                    r.push_back(s.substr(i - 9, 10));
                    m[t] = false;
                }
            }
            else
            {
                m[t] = true;
            }
        }
        return r;
    }
};
class Solution {
public:
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
         }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, pass, visited;
        string init = "0000";
        if (dds.find(init) != dds.end() || dds.find(target) != dds.end())
            return -1;
        visited.insert("0000");
        q1.insert("0000"), q2.insert(target);
        int res = 0;
        if(init == target)
            return res;
        while (!q1.empty() && !q2.empty())
        {
            if (q1.size() > q2.size())
                swap(q1, q2);
            pass.clear();
            for (auto ss : q1)
            {
                vector<string> nbrs = nbrStrs(ss);
                for (auto s : nbrs)
                {
                    if (q2.find(s) != q2.end())
                        return res + 1;
                    if (visited.find(s) != visited.end())
                        continue;
                    if (dds.find(s) == dds.end())
                    {
                        pass.insert(s);
                        visited.insert(s);
                    }
                }
            }
            swap(q1, pass);
            res++;
        }
        return -1;
    }
};
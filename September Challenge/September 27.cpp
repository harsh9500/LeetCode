class Solution {
public:
    double helper(unordered_map<string, unordered_map<string, double>> m, string start, string end, unordered_set<string> visited)
    {
        if(m[start].find(end)!=m[start].end())
        {
            return m[start][end];
        }
        visited.insert(start);
        for (auto entry : m[start])
        {
            if (visited.find(entry.first)!=visited.end())
                continue;
            double res=helper(m, entry.first, end, visited);
            if (res==-1.0)
                continue;
            return res*(entry.second);
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        for(int i=0;i<equations.size();i++)
        {
            string start=equations[i][0];
            string end=equations[i][1];
            double ratio=values[i];
            m[start][end]=ratio;
            m[end][start]=(1.0/ratio);
        }
        vector<double> res(queries.size(),-1.0);
        for (int i=0;i<queries.size();i++)
        {
            string start=queries[i][0];
            string end=queries[i][1];
            if (m.find(start)==m.end() || m.find(end)==m.end())
            {
                res[i] = -1.0;
                continue;
            }
            unordered_set<string> s;
            res[i]=helper(m, start, end, s);
        }
        return res;
    }
};
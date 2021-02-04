class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> m;
        int res=0;
        for (int num:nums)
        {
            if(m.find(num)!=m.end())
                m[num]++;
            else
                m[num]=1;
        }
        for (auto key: m)
        {
            if(m.find(key.first+1)!=m.end())
                res=max(res,m[key.first]+m[key.first+1]);
        }
        return res;
    }
};
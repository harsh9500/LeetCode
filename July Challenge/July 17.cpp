class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> alterMap;
        vector<int> answer;
        for(auto x:nums)
        {
            if(alterMap.find(x)==alterMap.end())
            {
                alterMap[x]=1;
            }
            else
            {
                alterMap[x]++;
            }
        }
        multimap<int,int> m;
        for(auto it=alterMap.begin(); it!=alterMap.end();it++)
        {
            m.insert({it->second,it->first});
        }
        for(auto it=m.rbegin();k!=0 && it!=m.rend();k--,it++)
        {
            answer.push_back(it->second);
        }
        return answer;
    }
};
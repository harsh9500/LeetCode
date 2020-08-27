class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> st_loc;
        int len = intervals.size();
        vector<int> en(len), vec(len, -1);
        for(int i=0; i<len; i++)
        {
            st_loc.insert({intervals[i][0], i});
            en[i] = intervals[i][1];
        }
        for(int i=0; i<len; i++)
        {
            auto rIndex = st_loc.lower_bound(en[i]);
            if(rIndex != st_loc.end())
                vec[i] = rIndex->second;
        }
        return vec;
    }
};